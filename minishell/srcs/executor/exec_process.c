/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:31:01 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/15 19:17:32 by aaespino         ###   ########.fr       */
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

/*

	builtin = ft_builtins(split_cmd); FUNCION QUE ME DIGA SI HAY BUILTIN

	exec_builtin(data, split_cmd, 1, builtin); FUNCION QUE LA EJECUTA, aka ft_builtin?

*/
void	exec_process(t_info *data, char	*cmd)
{
	int		builtin;
	char	**split_cmd;

	split_cmd = handle_cmd(cmd);
	builtin = ft_builtins(data);
	if (builtin)
	{
		return ;
		// if (ft_redirect(data))
		// 	exit (1);
		// exec_builtin(data, split_cmd, 1, builtin);
		// exit (0);
	}
	if (!cmd)
		exit(0);
	else
		do_exec(data, *split_cmd);
}
