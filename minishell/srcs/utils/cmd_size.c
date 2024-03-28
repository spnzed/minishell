/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:33:02 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/28 17:33:13 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmdsize(char **command)
{
	int	size;
	int	count;

	size = 0;
	if (ft_strlen(command[0]) > 0)
		size++;
	else
		return (size);
	count = ft_arrlen(command);
	while (size < count)
	{
		if (command[size][0] == '-')
			size++;
		else
			break ;
	}
	return (size);
}