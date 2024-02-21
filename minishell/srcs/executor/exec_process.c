/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:31:01 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/21 14:59:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**handle_cmd(char *cmd)
{
	char	*cleaned_cmd;
	char	**splitted_cmd;
	
	cleaned_cmd = clean_redir(cmd);
	splitted_cmd = split_quotes(cleaned_cmd);
	return (splitted_cmd);
}

static void	do_exec(t_info *data, char **splitted_cmd)
{
	char	*path;

	if (!ft_findalnum(splitted_cmd[0]))
		put_error(splitted_cmd[0], ": command not found\n", 127);
	path = find_cmd_route(data->signals_env, splitted_cmd[0]);
	if (!path)
		put_error(splitted_cmd[0], ": No such file or directory\n", 1);
	if (handle_redirect(data))
		exit (1);
	execve(path, splitted_cmd, data->list_env->content);
	put_error(splitted_cmd[0], ": command not found\n", 127);
	exit (127);
}

static void	do_builtin(t_info *data, int builtin)
{
	int	len;

	len = ft_strlen(data->cmd_line);
	if (builtin == 1)
		ft_env(&data->list_env);
	else if (builtin == 2)
		ft_pwd();
	else if (builtin == 3)
		ft_echo(data->cmd_line, len);
	else if (builtin == 4)
		ft_exit(data);
	else if (builtin == 5)
		ft_cd(data);
	else if (builtin == 6)
		ft_export(data);
	else if (builtin == 7)
		ft_unset(data);
}

void	exec_process(t_info *data, char	*cmd)
{
	int		builtin;
	char	**split_cmd;

	split_cmd = handle_cmd(cmd);
	builtin = is_builtin(data);
	if (builtin != 0)
	{
		if (handle_redirect(data))
			exit(1);
		do_builtin(data, builtin);
		exit(0);
	}
	else if (!cmd)
		exit(0);
	else
		do_exec(data, split_cmd);
}
