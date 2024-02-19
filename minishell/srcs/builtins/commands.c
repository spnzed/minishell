/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:48 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/19 15:06:24 by pquintan         ###   ########.fr       */
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

void	ft_builtins(t_info *data)
{
	int  len;

	len = cmd_line_size(data->cmd_line);
	if (ft_strcmp(data->cmd_line, "env") == 0)
		ft_env(&data->list_env);
	else if (ft_strcmp(data->cmd_line, "pwd") == 0)
		ft_pwd();
	else if (check_complex_cmd(data->cmd_line, "echo", 4) == 0 || check_complex_cmd(data->cmd_line, "echo -n", 7) == 0)
		ft_echo(data->cmd_line, len);
	else if (ft_strcmp(data->cmd_line, "exit") == 0)
		ft_exit(data);
	else if(check_complex_cmd(data->cmd_line, "cd", 2) == 0)
		ft_cd(data);
	else if(check_complex_cmd(data->cmd_line, "export", 6) == 0)
		ft_export(data);
	else if(check_complex_cmd(data->cmd_line, "unset", 5) == 0)
		ft_unset(data);
	else
	{
		printf("NOT BUILDIN\n");
		exit(0);
	}
	// 	error_exit(data); // arreglar error
}

// mirar en que casos si pones un espacio despues de el comando sigue funcionando