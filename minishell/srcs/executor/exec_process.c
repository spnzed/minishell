/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:31:01 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/19 18:36:23 by aaespino         ###   ########.fr       */
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

void	exec_process(t_info *data, char	*cmd)
{
	int		builtin;
	char	**split_cmd;

	split_cmd = handle_cmd(cmd);
	builtin = ft_builtins(data);
	if (builtin)
	{
		if (handle_redirect(data))
			exit(1);
		exit(0);
	}
	else if (!cmd)
		exit(0);
	else
		do_exec(data, split_cmd);
}
