/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/21 12:39:30 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_environmentsize(t_environment *env)
{
	int	size;

	size = 0;
	while (env)
	{
		env = env->next;
		size++;
	}
	return (size);
}

static t_environment	*order_exp(t_environment *exp)
{
	t_environment *exp_order;
	int len_list;
	int index;
	t_environment *temp;
	t_environment *tempvar;

	exp_order = ft_copy_environment(exp);
	len_list = ft_environmentsize(exp_order);
	index = 0;

	while (index < len_list)
	{
		temp = exp_order;
		while (temp->next != NULL)
		{
			if ((ft_strcmp(temp->signal, temp->next->signal)) > 0)
			{
				tempvar = temp->next;
				temp->next = temp->next->next;
				tempvar->next = exp_order;
				exp_order = tempvar;
			}
			else
				temp = temp->next;
		}
		index++;
	}
	return (exp_order);
}

static void	sub_var(t_list *list, char *signal, char *content)
{
	int		len;
	char	*new_content;

	len = ft_strlen(signal) + ft_strlen(content) + 2;
	while(list)
	{
		if (ft_strcmp(ft_before_set(list->content, '='), signal) == 0)
		{
			new_content = malloc(sizeof len);
			new_content = ft_strjoin(signal, "=");
			new_content = ft_strjoin(new_content, content);
			list->content = ft_memcpy(list->content, new_content, len);
		}
		list = list->next;
	}
}

static int	search_on_lists(t_info *data, t_environment *list, char *str)
{
	char	*signal;
	char	*content;

	signal = ft_before_set(str, '=');
	content = ft_after_set(str, '=');
	while (list)
	{
		if (ft_strcmp(signal, list->signal) == 0)
		{
			list->content = content;
			list->full_line = ft_strjoin(signal, "=");
			list->full_line = ft_strjoin(list->full_line, content);
			sub_var(data->list_env, signal, content);
			return(0);
		}
		list = list->next;
	}
	return(1);
}

static int	ft_envsize(t_environment *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return ((int)size);
}

static char	**ft_env_to_array(t_environment *head)
{
	int		i;
	int		strsize;
	int		lstsize;
	char	**array;
	t_environment	*temp;

	i = 0;
	lstsize = ft_envsize(head);
	array = malloc(sizeof(char *) * (lstsize + 1));
	if (!array)
		return (NULL);
	temp = head;
	while (i < lstsize)
	{
		strsize = ft_strlen(temp->signal) + 1 + ft_strlen(temp->content);
		if (ft_strlen(temp->content) > 0)
		{		
			array[i] = malloc(sizeof(char) * (strsize + 1));
			ft_strlcpy(array[i], temp->signal, strsize + 1);
			ft_strlcat(array[i], "=", strsize + 1);
			ft_strlcat(array[i], temp->content, strsize + 1);
		}
		temp = temp->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

static	void	export_equal(t_info *data, t_list *new, char *cmd)
{
	if (ft_strchr(cmd, '"'))
		cmd = ft_remove_quotes_str(cmd);
	if (search_on_lists(data, data->list_exp, cmd) == 0)
		return ;
	else
	{
		//printf("[%s] | [%s]\n", signal, list->signal);
		new = ft_lstnew(cmd);
		if (!new)
		{
			ft_lstclear(&data->list_env, free);
			return ;
		}
		if (!data->list_env)
			data->list_env = new;
		else
			ft_lstadd_back(&data->list_env, new);
		ft_free_environment(data->list_exp);
		data->list_exp = start_sig(order_env(data->list_env));
		data->env = ft_env_to_array(data->list_exp);
	}
}

static	void	export_else(t_info *data, t_environment *tmp, char *cmd)
{
	if (ft_strchr(cmd, '"'))
		cmd = ft_remove_quotes_str(cmd);
	tmp = ft_envnew(cmd);
	tmp->signal = cmd;
	if (!tmp)
	{
		ft_envclear(&data->list_exp, free);
		return ;
	} 
	if (!data->list_exp)
		data->list_exp = tmp;	
	else
		ft_envadd_back(&data->list_exp, tmp);
	data->list_exp = order_exp(data->list_exp);
	data->env = ft_env_to_array(data->list_exp);
}

static void	export_error_not_valid_id(char *arg, t_info *data)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(ft_remove_quotes_str(arg), 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	data->exit_id = 1;
}

static char	*first_num(char *var)
{
	int		x;
	int		y;
	char	*zero;

	x = 0;
	y = 0;
	zero = "";
	if (var[x] >= '0' && var[x] <= '9')
		return(var);
	return(zero);
}

static int export_valid(char *cmd)
{
	char	*non_alnum;
	char	*found;
	char	*var;

	var = ft_before_set(cmd, '=');
	//printf("[%s]\n", var);
	non_alnum = ft_strdup(" !#$%%&\\()*+,-./:;<>@[]^`{|}~");
	found = ft_strpbrk(var, non_alnum);
	//printf("found[%s][%d]\n", found, ft_strlen(found));
	found = ft_strjoin(found, first_num(var));
	//printf("found[%s][%d]\n", found, ft_strlen(found));
	if (ft_strlen(found) > 0)
		return(0);
	return(1);
}

static int	cmdsize(char **command)
{
	int	size;
	int	count;

	size = 0;
	if (ft_strlen(command[0]) > 0)
		size++;
	else
		return (size);
	count = ft_arrlen(command);
	while (size < count)
	{
		if (command[size][0] == '-')
			size++;
		else
			break ;
	}
	return (size);
}

int	ft_export(t_info *data, char **split_cmd)
{
	t_environment	*temp;
	t_list			*new;
	t_environment	*tmp;
	int x = cmdsize(split_cmd) - 1;
	int i = 1;

	temp = data->list_exp;
	new = NULL;
	tmp = NULL;
	while (split_cmd[i])
	{
		if (!export_valid(ft_remove_quotes_str(split_cmd[i])))
		{
			export_error_not_valid_id(ft_after_set(data->cmd_line, ' '), data);
			return (1);	
		}
		i++;	
	}
	i = 1;
	//printf("[%d] | [%d]\n", ((x + 1) == 1), (ft_arrlen(split_cmd) == 1));
	if (((x + 1) == 1) && (ft_arrlen(split_cmd) == 1))//if(ft_strcmp(data->cmd_line, "export") == 0)
	{
		while(temp)
		{
			printf("declare -x %s", temp->signal);
			if (temp->content != NULL)
				printf("=\"%s\"\n", temp->content);
			else
				printf("\n");
			temp = temp->next;
		}		
	}
	// hay que ver como lo hacemos cuando haya varias variables en un comando
	else if (ft_strchr(split_cmd[1], '='))
		while (split_cmd[i])
		export_equal(data, new, split_cmd[i++]);
	else
		while (split_cmd[i])
			export_else(data, tmp, split_cmd[i++]);
	return (0);
}

/*
pquintan@cbr12s4 ~ % export      ADIOS =
zsh: bad assignment
*/

// cuando pones export HOLA sin un igual detras se guarda en export y no en env
/*
no se puede poner un numero al principio del nombre de la variable ejemplo:
bash-3.2$ export 3GOL="no"
bash: export: `3GOL=no': not a valid identifier
bash: export: `.gol3=si': not a valid identifier // ni punto
// deduzco que solo letras 
*/

/*
42-Minishell ~ % export ADIOS="vamoooooooooos"
actualizado
antes: ADIOS=vamoooooooADIOS
despues: ADIOS=vamoooooooADIOS
*/

/*
bash-3.2$ export '  B=valdue '
bash: export: `  B=valdue ': not a valid identifier
bash-3.2$ export '  B=value '
bash: export: `  B=value ': not a valid identifier
bash-3.2$ export '  B=value'
bash: export: `  B=value': not a valid identifier
bash-3.2$ export 'B=value'
bash-3.2$ export ' B=value'
bash: export: ` B=value': not a valid identifier
bash-3.2$ export  C=value
bash-3.2$ export  C=value
*/ //normaliza solo lo que hay sin comillas, al final si le gustan los espacios