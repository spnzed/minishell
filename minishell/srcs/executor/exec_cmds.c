/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:27:44 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 19:58:25 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wait_childs(t_info *data)
{
	int	nbr;
	int	pid;
	int	status;

	nbr = data->cmd_nbr;
	while (nbr--)
	{
		pid = waitpid(-1, &status, 0);
		if (nbr == 0 && WIFSIGNALED(status))
		{
			status += 128;
			catch_signal(data, status, 0);
		}
		else if (pid == data->pid)
			if (WIFEXITED(status))
				data->exit_id = WEXITSTATUS(status);
	}
	return ;
}

int	exec_cmds(t_info *data)
{
	int	i;

	i = -1;
	signal(SIGINT, SIG_IGN);
	if (data->cmd_nbr > 1 && ft_strnstr(data->cmd_line, "<<",
			ft_strlen(data->cmd_line)))
		handle_heredoc_pipe(data);
	while (++i < data->cmd_nbr)
	{
		pipe(data->fd);
		signal(SIGINT, SIG_IGN);
		data->pid = fork();
		if (call_childs(data, i))
			parent_process(data);
	}
	wait_childs(data);
	return (0);
}
