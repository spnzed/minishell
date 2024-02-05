/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:47:17 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/02 19:27:04 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

char	*put_status(t_info *data, char *var)
{	
	char	*cmd_ret;
	char	*result;

	cmd_ret = ft_itoa(data->cmd_return);
	result = put_variable(data->cmd_line, var, cmd_ret);
	free(cmd_ret);
	free(data->cmd_line);
	return (result);
}

t_list	*var_is_found(t_list *list_env, char *var)
{
	t_list	*top;

	top = list_env;
	while (top != NULL)
	{
		if (ft_strcmp(top->content, var) == 0)
			return (top);
		top = top->next;
	}
	return (NULL);
}

char	*parse_var(t_info *data)
{
	char	*var;
	char	*res;

	var = search_var(data->cmd_line);
	if (var && ft_strlen(var))
	{
		var = export_id(var);
		if (ft_strcmp(var, "?") == 0)
			return (put_status(data, var));
		else
		{
			if (var_is_found(data->list_env, var))
				res = put_variable(data->cmd_line, var, "");
			else
				res = put_variable(data->cmd_line, var, "");
			free(var);
			free(data->cmd_line);
			return(res);
		}
	}
	return (data->cmd_line);
}
