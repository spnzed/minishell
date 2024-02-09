/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:31:01 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/09 15:48:04 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char **split_quotes(char **cmd)
{
	return (cmd);	
}

static void	do_exec(t_info *data, char	*cmd)
{
	(void)data;
	(void)cmd;
	return ;
}

static char	**handle_cmd(char *cmd)
{
	char	*cleaned_cmd;
	char	**splitted_cmd;
	
	cleaned_cmd = clean_redir(cmd);
	splitted_cmd = split_quotes(&cleaned_cmd);
	return (splitted_cmd);
}

void	exec_process(t_info *data, char	*cmd)
{
	int		builtin;
	char	**split_cmd;

	builtin = 1; //ft_builtins(data);
	split_cmd = handle_cmd(cmd);
	if (!cmd)
		exit(0);
	else if (builtin)
		exit(0);
	else
		do_exec(data, *split_cmd);
}
