/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:31:01 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/14 19:15:21 by aaespino         ###   ########.fr       */
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

static void	do_exec(t_info *data, char	*cmd)
{
	(void)data;
	(void)cmd;
	return ;
}

void	exec_process(t_info *data, char	*cmd)
{
	int		builtin;
	char	**split_cmd;

	split_cmd = handle_cmd(cmd);
	builtin = 1; //ft_builtins(data);
	if (!cmd)
		exit(0);
	else if (builtin)
		exit(0);
	else
		do_exec(data, *split_cmd);
}

/*

	ft_get_redit_value(raw_cmd, data);
	cleaned_cmd = ft_clean_redir_cmd(raw_cmd);
	splitted_cmd = ft_split_quotes(cleaned_cmd);
	builtin = is_builtin(splitted_cmd);
	if (builtin)
	{
		if (ft_redirect(data))
			exit (1);
		exec_builtin(data, splitted_cmd, 1, builtin);
		exit (0);
	}
	else if (!raw_cmd[0])
		exit(0);
	else
		exec_generic_multiple(data, splitted_cmd);

*/