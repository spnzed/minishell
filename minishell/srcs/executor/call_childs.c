/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:26:03 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/26 14:26:51 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_process(t_info *data, int nbr)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	if (nbr != data->cmd_nbr - 1)
	{
		dup2(data->fd[1], STDOUT_FILENO);
	}
	close(data->fd[1]);
	close(data->fd[0]);
	exec_process(data, data->split_line[nbr]);
}

int	call_childs(t_info *data, int i)
{
	if (data->pid < 0)
	{
		close(data->fd[1]);
		close(data->fd[0]);
		exit (0);
	}
	if (data->pid == 0)
		return (child_process(data, i), 0);
	return (1);
}
