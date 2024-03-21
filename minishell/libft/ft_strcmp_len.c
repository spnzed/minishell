/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:28:19 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/21 15:31:39 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_len(char *strbase, char *strcomp, int len)
{
	int	x;
	int	y;
	int	base;

	x = 0;
	y = 0;
	base = 0;
	while (strbase[base] && strcomp[x])
	{
		if (strbase[base] == strcomp[x])
			y++;
		base++;
		x++;
	}
	if (y == len)
		return (0);
	else
		return (1);
}
