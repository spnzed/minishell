/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_complex_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:48:19 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/22 11:44:17 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_complex_cmd(char *strbase, char *strcomp, int len)
{
	int		x;
	int		y;
	int		base;
	char	*test;

	x = 0;
	y = 0;
	base = 0;
	test = ft_before_set(strbase, ' ');
	if (ft_strlen(test) != len)
		return (1);
	while (strbase[base] && (strbase[base] == ' ' || strbase[base] == '\n'
			|| strbase[base] == '\t'))
		base++;
	while (strbase[base] && x < len)
	{
		if (strbase[base] == strcomp[x])
			y++;
		x++;
		base++;
	}
	if (x == len && y == x)
		return (0);
	else
		return (1);
}
