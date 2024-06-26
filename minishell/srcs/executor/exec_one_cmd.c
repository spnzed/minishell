/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:10:12 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/01 15:21:02 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_one(t_info *data)
{
	char	*path;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	if (!ft_isstrprint(data->one_cmd[0]) && !comprove_redirs(data))
		exit (0);
	if (handle_redirect(data))
		exit (1);
	filter_one_cmd(data, &data->one_cmd[0]);
	path = find_cmd_route(data->list_exp, data->one_cmd[0]);
	if (!path && !comprove_redirs(data))
		put_error(data, data->one_cmd[0],
			": No such file or directory\n", 127);
	execve(path, data->one_cmd, data->env);
	if (!comprove_redirs(data))
		last_error(data);
	exit (127);
}

static int	one_bultin(t_info *data)
{
	int	builtin;

	builtin = is_builtin(data->one_cmd, data);
	if (builtin)
	{
		if (handle_redirect(data))
			return (1);
		do_builtin (data, builtin, data->one_cmd);
		return (1);
	}
	return (0);
}

int	exec_one_cmd(t_info *data)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	if (one_bultin(data))
		return (1);
	else
	{
		data->pid = fork();
		if (data->pid == -1)
			return (1);
		else if (data->pid == 0)
			exec_one(data);
		waitpid(data->pid, &status, 0);
		if (WIFSIGNALED(status))
			catch_signal(data, status + 128, 1);
		else if (WIFEXITED(status))
			data->exit_id = WEXITSTATUS(status);
	}
	return (0);
}
