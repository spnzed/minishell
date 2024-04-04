/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/04 19:25:17 by pquintan         ###   ########.fr       */
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
		return ;
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
		data->list_exp = order_exp(data->list_exp);
		data->signals_env = start_sig(data->list_env);
		data->env = ft_env_to_array(data->list_exp);
	}
}

static void	export_else(t_info *data, char *cmd)
{
	t_environment	*tmp;

	tmp = NULL;
	if (ft_strchr(cmd, '"'))
		cmd = ft_remove_quotes_str(cmd);
	if (search_list_else(data->list_exp, cmd) == 0)
		return ;
	tmp = ft_envnew(cmd);
	tmp->signal = cmd;
	tmp->content = NULL;
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

static void	export_function(int i, int x, t_info *data, char **split_cmd)
{
	t_environment	*temp;
	t_list			*new;

	new = NULL;
	temp = data->list_exp;
	export_and_grep(temp, split_cmd, x);
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
}

int	ft_export(t_info *data, char **split_cmd)
{
	int				x;
	int				i;

	x = cmdsize(split_cmd) - 1;
	i = 1;
	export_function(1, x, data, split_cmd);
	return (0);
}
