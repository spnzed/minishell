/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:35:40 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/15 18:38:00 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_cmds(t_info *data)
{
	int		i;
	int		len;
	char	**splitted;

	i = -1;
	splitted = split_pipe(data->cmd_line, '|');
	while (splitted[++i])
	{
		printf("cmd nbr %d : /%s/\n", i, splitted[i]);
	}
	len = ft_arrlen(splitted);
	while (splitted[++i])
		;
	return (splitted);
}