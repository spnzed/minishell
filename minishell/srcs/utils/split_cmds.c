/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:35:40 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/15 19:07:45 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//aqui tenemos que estudiar los check_pipe
char	**split_cmds(t_info *data)
{
	int		i;
	char	**splitted;

	i = -1;
	splitted = split_pipe(data->cmd_line, '|');
	return (splitted);
}

/*

	len = ft_arrlen(splitted);
	while (splitted[++i])
		if (check_pipe(splitted, i, len))
			return (NULL);

*/