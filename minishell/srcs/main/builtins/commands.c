/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:48 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/05 16:35:55 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_line_size(char* cmd_line)
{
	int x;

	x = 0;
	while(cmd_line[x])
		x++;
	return(x);
}

int	is_env(char	*line, int len)
{
	char *var;
	int x = 0;
	int temp = len;
	var = "env";
	while(line[x] && var[x] && len != x)
	{
		if (line[x] == var[x])
		{
			x++;
			len--;
		}
	}
	//printf("x: %d, temp: %d, len: %d\n", x, temp, len);
	if (x == temp && x != len)
		return(1);
	else
		return(0);
}

void	ft_builtins(t_info *data)
{
	int len;
	
	len = cmd_line_size(data->cmd_line);
	if (is_env(data->cmd_line, len))
	{
		printf("entra?\n");
		ft_env(&data->list_env);
	}
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