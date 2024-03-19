/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/12 16:35:39 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_equal(t_info *data, t_list *new)
{
	data->str_trim = ft_after_set(data->cmd_line, ' ');
	if (ft_strchr(data->str_trim, '"'))
		data->str_trim = ft_remove_quotes_str(data->str_trim);
	if (search_on_lists(data, data->list_exp, data->str_trim) == 0)
	{
		new = ft_lstnew(data->str_trim);
		ft_lstadd_back(&data->list_env, new);
		return ;
	}
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
		ft_free_env(data->list_exp);
		data->list_exp = start_sig(order_env(data->list_env));
		data->env = ft_env_to_array(data->list_exp);
	}
}

static	void	export_else(t_info *data, t_env *tmp, char **split_cmd)
{
	data->str_trim = split_cmd[1];
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
	data->env = ft_env_to_array(data->list_exp);
}

static int	export_error_not_valid_id(char *arg, t_info *data)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(ft_remove_quotes_str(arg), 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	data->exit_id = 1;
	return (1);
}

static int	export_valid(char **split_cmd)
{
	char	*non_alnum;
	char	*alnum;
	char	*found;
	char	*var;

	var = ft_before_set(split_cmd[1], '=');
	non_alnum = ft_strdup(" !#$%%&\\()*+,-./:;<>@[]^`{|}~");
	alnum = ft_strdup("1234567890");
	found = ft_strpbrk(var, non_alnum);
	found = ft_strjoin(found, ft_strpbrk(var, alnum));
	if (ft_strlen(found) > 0)
		return (0);
	return (1);
}

int	ft_export(t_info *data, char **split_cmd)
{
	t_env	*temp;
	t_list	*new;
	t_env	*tmp;

	temp = data->list_exp;
	new = NULL;
	tmp = NULL;
	if (!export_valid(split_cmd))
		export_error_not_valid_id(ft_after_set(data->cmd_line, ' '), data);
	if (ft_strcmp(split_cmd[0], "grep") == 0)
	{
		while (temp)
		{
			if (ft_strcmp(temp->signal, split_cmd[1]) == 0)
			{
				printf("declare -x %s", temp->signal);
				if (temp->content != NULL)
					printf("=\"%s\"\n", temp->content);
				else
					printf("\n");
			}
			temp = temp->next;
		}
	}
	else if (ft_strcmp(data->cmd_line, "export") == 0)
	{
		while (temp)
		{
			printf("declare -x %s", temp->signal);
			if (temp->content != NULL)
				printf("=\"%s\"\n", temp->content);
			else
				printf("\n");
			temp = temp->next;
		}
	}
	else if (ft_strchr(split_cmd[1], '='))
		export_equal(data, new);
	else
		export_else(data, tmp, split_cmd);
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