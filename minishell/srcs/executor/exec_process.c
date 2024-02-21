/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:31:01 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/21 12:20:23 by pquintan         ###   ########.fr       */
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

void	exec_process(t_info *data, char	*cmd)
{
	int		builtin;
	char	**split_cmd;

	split_cmd = handle_cmd(cmd);
	builtin = ft_builtins(data);
	if (builtin != 0)
	{
		printf("built: %d\n", builtin);
		if (handle_redirect(data))
			exit(1);
		exit(0);
	}
	else if (!cmd)
		exit(0);
	else
		do_exec(data, split_cmd);
}
