/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/10 14:27:05 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_envsize(t_environment *lst)
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

static void	export_equal(t_info *data, t_list *new, char *cmd)
{
	if (ft_strchr(cmd, '"'))
		cmd = ft_remove_quotes_str(cmd);
	if (search_on_lists(data, data->list_exp, cmd) == 0)
	{
		data->signals_env = start_sig(data->list_env);
		return ;
	}
	else
	{
		list_exp_add(cmd, data);
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
		order_exp(data->list_exp);
		free_environment(data->signals_env);
		data->signals_env = start_sig(data->list_env);
	}
}

static void	export_else(t_info *data, char *cmd)
{
	char			*aux;
	t_environment	*tmp;

	tmp = NULL;
	aux = ft_strdup (cmd);
	if (ft_strchr(aux, '"'))
		aux = ft_remove_quotes_str(aux);
	if (search_list_else(data->list_exp, aux) == 0)
		return ;
	tmp = ft_envnew(aux);
	tmp->signal = aux;
	tmp->content = NULL;
	if (!tmp)
	{
		ft_envclear(&data->list_exp, free);
		free(aux);
		return ;
	}
	if (!data->list_exp)
		data->list_exp = tmp;
	else
		ft_envadd_back(&data->list_exp, tmp);
	free(aux);
	order_exp(data->list_exp);
}

static void	export_function(int i, int x, t_info *data, char **split_cmd)
{
	t_environment	*temp;
	t_list			*new;

	new = NULL;
	temp = data->list_exp;
	export_and_grep(temp, split_cmd, x);
	data->exit_id = 0;
	while (split_cmd[i])
	{
		if (!export_valid(ft_remove_quotes_str(split_cmd[i])))
			export_error_not_valid_id(split_cmd[i++], data);
		else
		{
			if (ft_strchr(split_cmd[i], '='))
				export_equal(data, new, split_cmd[i++]);
			else
				export_else(data, split_cmd[i++]);
		}
	}
	free_array(data->env);
	data->env = ft_env_to_array(data->list_exp);
}

int	export_builtin(t_info *data, char **split_cmd)
{
	int				x;
	int				i;

	x = cmdsize(split_cmd) - 1;
	i = 1;
	export_function(1, x, data, split_cmd);
	return (0);
}
