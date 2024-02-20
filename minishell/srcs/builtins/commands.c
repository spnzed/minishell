/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:48 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/20 17:47:24 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	cmd_line_size(char* cmd_line)
{
	size_t x;

	x = 0;
	while(cmd_line[x])
		x++;
	return(x);
}

int	ft_builtins(t_info *data)
{
	int	len;
	int	b;

	len = cmd_line_size(data->cmd_line);
	b = 0;
	if (ft_strcmp(data->cmd_line, "env") == 0)
		b = ft_env(&data->list_env);
	else if (ft_strcmp(data->cmd_line, "pwd") == 0)
		b = ft_pwd();
	else if (check_complex_cmd(data->cmd_line, "echo", 4) == 0 || check_complex_cmd(data->cmd_line, "echo -n", 7) == 0)
		b = ft_echo(data->cmd_line, len);
	else if (ft_strcmp(data->cmd_line, "exit") == 0)
		b = ft_exit(data);
	else if(check_complex_cmd(data->cmd_line, "cd", 2) == 0)
		b = ft_cd(data);
	else if(check_complex_cmd(data->cmd_line, "export", 6) == 0)
		b = ft_export(data);
	else if(check_complex_cmd(data->cmd_line, "unset", 5) == 0)
		b = ft_unset(data);
	else
		return(b);
	// 	error_exit(data); // arreglar error
	return(b);
}

// mirar en que casos si pones un espacio despues de el comando sigue funcionando