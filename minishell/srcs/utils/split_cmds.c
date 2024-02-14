/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:35:40 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/14 19:58:07 by aaespino         ###   ########.fr       */
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
	len = ft_array_size(splitted);
	while (splitted[++i])
		if (found_pipe(splitted, i, len))
			return (NULL); 
	return (splitted);
}