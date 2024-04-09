/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:31:01 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/09 18:16:10 by pquintan         ###   ########.fr       */
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

static void	filter_cmd(t_info *data, char *cmd)
{
	if (ft_strcmp(cmd, " ") == 0)
		put_error(data, " line 1: ", ": command not found\n", 127);
	if (ft_strcmp(cmd, "~") == 0)
	{
		ft_putstr_fd("minishell: line 1: ", 2);
		ft_putstr_fd(data->home, 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit (126);
	}
}

static void	do_exec(t_info *data, char **splitted_cmd, int i)
{
	char	*path;
	char	*aux;

	aux = remove_quotes(splitted_cmd[0]);
	if (ft_strlen(aux) == 0
		&& ft_strcmp(data->heredoc_keys[i], "PLACEHOLDER") != 0)
		exit (0);
	if (aux)
		filter_cmd(data, aux);
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
		env_builtin(data, data->list_env);
	else if (builtin == 2)
		pwd_builtin(data);
	else if (builtin == 3)
		echo_builtin(data, split_cmd);
	else if (builtin == 4)
		exit_builtin(data, split_cmd);
	else if (builtin == 5)
		cd_builtin(data, split_cmd);
	else if (builtin == 6)
		export_builtin(data, split_cmd);
	else if (builtin == 7)
		unset_builtin(data, split_cmd);
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
		do_exec(data, split_cmd, i);
	}
}
