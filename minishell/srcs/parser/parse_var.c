/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:47:17 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/20 16:48:59 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*put_status(t_info *data, char *var)
{	
	char	*cmd_ret;
	char	*result;

	cmd_ret = ft_itoa(data->cmd_return);
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
			if (var_found(data->signals_env, var))
			{
				env = assign_var(data->signals_env, var);
				res = put_variable(data->cmd_line, env->signal, env->content);
			}
			else
				res = put_variable(data->cmd_line, var, "");
			free(var);
			free(data->cmd_line);
			return(res);
		}
	}
	return (data->cmd_line);
}
