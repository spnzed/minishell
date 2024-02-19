/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:16:29 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/19 19:23:50 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	do_exec(t_info *data, char **cmds)
{
	char	*path;

	if (!ft_findalnum(cmds[0]))
		put_error(cmds[0], ": command not found\n", 127);
	path = find_route(data->list_env, cmds[0]);
	if (!path)
		put_error(cmds[0], ": No such file or directory\n", 1);
	if (handle_redirect(data))
		exit (1);
	execve(path, cmds, data->list_env);
	put_error(cmds[0], ": command not found\n", 127);
	exit (127);
}
