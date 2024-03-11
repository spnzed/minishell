/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:47:17 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/11 18:00:54 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*put_status(t_info *data, char *var)
{
	char	*cmd_ret;
	char	*result;

	cmd_ret = ft_itoa(data->exit_id);
	result = put_variable(data->cmd_line, var, cmd_ret);
	free(cmd_ret);
	free(data->cmd_line);
	return (result);
}

static t_environment	*assign_var(t_environment *list_env, char *var)
{
	t_environment	*top;

	top = list_env;
	while (top)
	{
		if (ft_strcmp(top->signal, var) == 0)
			return (top);
		top = top->next;
	}
	return (NULL);
}

char	*parse_var(t_info *data)
{
	char			*var;
	char			*res;
	t_environment	*env;

	var = search_var(data->cmd_line);
	if (var && ft_strlen(var))
	{
		var = export_id(var);
		if (ft_strcmp(var, "?") == 0)
			return (put_status(data, var));
		else
		{
			if (var_found_env(data->signals_env, var))
			{
				env = assign_var(data->signals_env, var);
				res = put_variable(data->cmd_line, env->signal, env->content);
			}
			else
				res = put_variable(data->cmd_line, var, "");
			free(var);
			free(data->cmd_line);
			return (res);
		}
	}
	return (data->cmd_line);
}
