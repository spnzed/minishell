/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:48 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/06 16:13:54 by pquintan         ###   ########.fr       */
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
	else if (ft_check_complex_cmd(data->cmd_line, "echo", 4) == 0 || ft_check_complex_cmd(data->cmd_line, "echo -n", 7) == 0)
		ft_echo(data->cmd_line, len);
	// else if(ft_strcmp(data->cmd_line, "cd") == 0)// funcion aparte
	// 	ft_cd();
	// else
	// 	printf("command error\n"); // arreglar error
	/*while(data->cmd_line)
	{
		if (is_env(data->cmd_line, len))
			ft_env(data);
		else
			printf("command error\n"); // arreglar error
		//exit(0);
	}*/
}

// mirar en que casos si pones un espacio despues de el comando sigue funcionando