/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/08 10:54:58 by pquintan         ###   ########.fr       */
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
	int		len_signal;
	int		len;
	char	*new_content;

	len_signal = ft_strlen(signal);
	len = ft_strlen(signal) + ft_strlen(content) + 2;
	while(list)
	{
		if (check_complex_cmd(list->content, signal, len_signal) == 0)
		{
			free(list->content);
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
		array[i] = malloc(sizeof(char) * (strsize + 1));
		ft_strlcpy(array[i], temp->signal, strsize + 1);
		ft_strlcat(array[i], "=", strsize + 1);
		ft_strlcat(array[i], temp->content, strsize + 1);
		temp = temp->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

static	void	export_equal(t_info *data, t_list *new)
{
	data->str_trim = ft_after_set(data->cmd_line, ' ');
	if (ft_strchr(data->str_trim, '"'))
		data->str_trim = ft_remove_quotes_str(data->str_trim);
	if (search_on_lists(data, data->list_exp, data->str_trim) == 0)
		return ;
	else
	{
		new = ft_lstnew(data->str_trim);
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
		data->env = ft_env_to_array(data->list_exp); // no se si hace su funcion
	}
}

static	void	export_else(t_info *data, t_environment *tmp)
{
	data->str_trim = ft_strtrim(data->cmd_line, "export ");
	if (ft_strchr(data->str_trim, '"'))
		data->str_trim = ft_remove_quotes_str(data->str_trim);
	tmp = ft_envnew(data->str_trim);
	tmp->signal = data->str_trim;
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
	// int x = 0;
	// while (data->env)
	// 	printf("%s\n", data->env[x++]);
	//data->env = ft_env_to_array(data->list_exp);
} // IN PROCCESS

static void	export_error_not_valid_id(char *arg, t_info *data)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(ft_remove_quotes_str(arg), 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	data->exit_id = 1;
}

static int export_valid(t_info *data)
{
	char	*non_alnum;
	char	*alnum;
	char	*found;
	char	*var;

	var = ft_after_set(data->cmd_line, ' ');
	var = ft_before_set(var, '=');
	non_alnum = ft_strdup(" !#$%%&\\()*+,-./:;<>@[]^`{|}~");
	alnum = ft_strdup("1234567890");
	found = ft_strpbrk(var, non_alnum);
	found = ft_strjoin(found, ft_strpbrk(var, alnum));
	if (ft_strlen(found) > 0)
		return(0);
	return(1);
}

int	ft_export(t_info *data)
{
	t_environment	*temp;
	t_list			*new;
	t_environment	*tmp;

	temp = data->list_exp;
	new = NULL;
	tmp = NULL;
	if (!export_valid(data))
	{
		export_error_not_valid_id(ft_after_set(data->cmd_line, ' '), data);
		return(1);	
	}
	if(ft_strcmp(data->cmd_line, "export") == 0)
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
	else if (ft_strchr(data->cmd_line, '='))
		export_equal(data, new);
	else
		export_else(data, tmp);
	return(0);
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