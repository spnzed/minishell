/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:10:12 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/11 18:31:49 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isstrprint(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_isprint(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	filter_cmd(t_info *data, char **splitted_cmd)
{
	char	*home;

	home = get_var_list(data->list_env, "HOME")->content + 5;
	if (ft_strcmp(splitted_cmd[0], " ") == 0)
		put_error(data, " line 1: ", ": command not found\n", 127);
	if (ft_strcmp(splitted_cmd[0], "~") == 0)
	{
		ft_putstr_fd("minishell: line 1: ", 2);
		ft_putstr_fd(home, 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit (126);
	}
}

static void	exec_one(t_info *data)
{
	char	*path;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	if (!ft_isstrprint(data->one_cmd[0]))
		put_error(data, data->one_cmd[0], ": command not found\n", 127);
	filter_cmd(data, &data->one_cmd[0]);
	path = find_cmd_route(data->signals_env, data->one_cmd[0]);
	if (!path)
	{
		if (ft_strchr(data->one_cmd[0], '/'))
			put_error(data, data->one_cmd[0], ": No such file or directory\n", 1);
		else
			put_error(data, data->one_cmd[0], ": command not found\n", 127);
	}
	if (handle_redirect(data))
		exit (1);
	execve(path, data->one_cmd, data->env);
	put_error(data, data->one_cmd[0], ": command not found\n", 127);
	exit (127);
}

static int	one_bultin(t_info *data)
{
	int	builtin;

	builtin = is_builtin(data);
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
