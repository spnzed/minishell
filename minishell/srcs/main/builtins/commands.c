/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:48 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/05 14:32:50 by pquintan         ###   ########.fr       */
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
	// printf("x; %d || len: %d\n", x, len);
	while(line[x] && var[x] && len != x)
	{
		if (line[x] == var[x])
		{
			// printf("line %c, var %c\n", line[x], var[x]);
			x++;
			len--;
		}
	}
	// printf("x; %d || temp: %d\n", x, temp);
	if (x == temp)
		return(1);
	else
		return(0);
}

void	ft_builtins(t_info *data)
{
	int len;
	
	len = cmd_line_size(data->cmd_line);
	// printf("len: %d\n", len);
	while(data->cmd_line)
	{
		if (is_env(data->cmd_line, len))
			ft_env(data);
		else
		{
			printf("command error\n");
		}// to see if it goes before
		exit(0);
	}
}