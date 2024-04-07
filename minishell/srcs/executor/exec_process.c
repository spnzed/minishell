/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:31:01 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/07 16:34:00 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**handle_cmd(char *cmd)
{
	char	*cleaned_cmd;
	char	**splitted_cmd;

	cleaned_cmd = clean_redir(cmd);
	splitted_cmd = split_quotes(cleaned_cmd);
	free(cleaned_cmd);
	return (splitted_cmd);
}

static void	filter_cmd(t_info *data, char **splitted_cmd)
{
	if (ft_strcmp(splitted_cmd[0], " ") == 0)
		put_error(data, " line 1: ", ": command not found\n", 127);
	if (ft_strcmp(splitted_cmd[0], "~") == 0)
	{
		ft_putstr_fd("minishell: line 1: ", 2);
		ft_putstr_fd(data->home, 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit (126);
	}
}

static void	do_exec(t_info *data, char **splitted_cmd)
{
	char	*path;
	char	*aux;

	aux = ft_strtrim(splitted_cmd[0], "\"");
	filter_cmd(data, &aux);
	path = find_cmd_route(data->list_exp, aux);
	if (!path)
		put_error(data, aux, ": No such file or directory\n", 127);
	execve(path, splitted_cmd, data->env);
	put_error(data, aux, ": command not found\n", 127);
	exit (127);
}

void	do_builtin(t_info *data, int builtin, char **split_cmd)
{
	int	len;

	len = ft_strlen(data->cmd_line);
	if (builtin == 1)
		ft_env(data->list_env);
	else if (builtin == 2)
		ft_pwd(data);
	else if (builtin == 3)
		ft_echo(data, split_cmd);
	else if (builtin == 4)
		ft_exit(data, split_cmd);
	else if (builtin == 5)
		ft_cd(data, split_cmd);
	else if (builtin == 6)
		ft_export(data, split_cmd);
	else if (builtin == 7)
		ft_unset(data, split_cmd);
}

void	exec_process(t_info *data, char	*cmd, int i)
{
	int		builtin;
	char	**split_cmd;

	get_redirections(cmd, data);
	split_cmd = handle_cmd(cmd);
	builtin = is_builtin(split_cmd, data);
	if (builtin)
	{
		if (handle_redirect_mul(data, i))
			exit (1);
		do_builtin(data, builtin, split_cmd);
		exit (0);
	}
	else if (!cmd)
		exit (0);
	else
	{
		if (handle_redirect_mul(data, i))
			exit (1);
		do_exec(data, split_cmd);
	}
}
