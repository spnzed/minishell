/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:54:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/07 16:31:21 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_process(t_info *data, int nbr)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	if (nbr != data->cmd_nbr - 1)
		dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[1]);
	close(data->fd[0]);
}

static void	parent_process(t_info *data)
{
	dup2(data->fd[0], STDIN_FILENO);
	close(data->fd[0]);
	close(data->fd[1]);
}

//SIGINT : CTRL+C
//SIG_IGN : Ignorar
//PID: Process ID
int	exec_cmds(t_info *data)
{
	int	i;

	i = -1;
	while (++i < data->cmd_nbr)
	{
		pipe(data->fd);
		signal(SIGINT, SIG_IGN);
		data->pid = fork();
		if (data->pid < 0)
		{
			close(data->fd[1]);			// Cerrar el extremo de escritura del tubo
			close(data->fd[0]);			// Cerrar el extremo de lectura del tubo
			exit (0);
		}
		if (data->pid == 0)
		{
			child_process(data, i);
			exec_process(data, data->mul_cmds[i]);
		}
		parent_process(data);
	}
	wait_childs(data);
	return (0);
}