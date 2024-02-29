/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:31:01 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/26 19:00:14 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void print_array(char **splitted_cmd)
// {
// 	int i = 0;

// 	while (splitted_cmd[i])
// 	{
// 		printf("PRINTING ARRAY: |%s|\n", splitted_cmd[i]);
// 		i++;
// 	}
// }

static char	**handle_cmd(char *cmd)
{
	char	*cleaned_cmd;
	char	**splitted_cmd;
	
	cleaned_cmd = clean_redir(cmd);
	splitted_cmd = split_quotes(cleaned_cmd);
//	print_array(splitted_cmd);
//	splitted_cmd = ft_split(splitted_cmd[0], ' ');
	return (splitted_cmd);
}

static void	do_exec(t_info *data, char **splitted_cmd)
{
	char	*path;

	if (!ft_findalnum(splitted_cmd[0]))
		put_error(data, splitted_cmd[0], ": command not found\n", 127);
	path = find_cmd_route(data->signals_env, splitted_cmd[0]);
	if (!path)
	{
		if (ft_strchr(splitted_cmd[0], '/'))
			put_error(data, splitted_cmd[0], ": No such file or directory\n", 1); 
		else
			put_error(data, splitted_cmd[0], ": command not found\n", 127);
	}
	if (handle_redirect(data))
		exit (1);
	execve(path, splitted_cmd, NULL);
	put_error(data, splitted_cmd[0], ": command not found\n", 127);
	exit (127);
//	mirar si esta incorporado
//	if (data->is_builtin == 0)
//		put_error(data, data->cmd_line, ": command not found", 127); // "bash: line 1: "
}

static void	do_builtin(t_info *data, int builtin, char **split_cmd)
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
		ft_export(data);
	else if (builtin == 7)
		ft_unset(data);
	//data->cmd_line = normalizer(data->split_line[0]); // ft_strtrim mirar si hace lo mismo
}

// static void	do_builtin(t_info *data, int builtin)
// {
// 	int	len;
	
// 	len = ft_strlen(data->cmd_line);
// 	if (builtin == 1)
// 		ft_env(&data->list_env);
// 	else if (builtin == 2)
// 		ft_pwd();
// 	else if (builtin == 3)
// 		ft_echo(data, data->cmd_line, len);
// 	else if (builtin == 4)
// 		ft_exit(data);
// 	else if (builtin == 5)
// 		ft_cd(data);
// 	else if (builtin == 6)
// 		ft_export(data);
// 	else if (builtin == 7)
// 		ft_unset(data);
// 	//data->cmd_line = normalizer(data->split_line[0]); // ft_strtrim mirar si hace lo mismo
// }

void	exec_process(t_info *data, char	*cmd)
{
	int		builtin; // data->is_builtin
	char	**split_cmd;

	get_redirections(cmd, data);
	split_cmd = handle_cmd(cmd);
	builtin = is_builtin(data);
	if (builtin != 0)
	{
		if (handle_redirect(data))
			exit(1);
		do_builtin(data, builtin, split_cmd);
		//printf("Before chdir: %s\n", getcwd(NULL, 0));
		exit(0);
	}
	else if (!cmd)
		exit(0);
	else
		do_exec(data, split_cmd);
	printf("\n");
}
