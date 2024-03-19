/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_complex_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:48:19 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/19 16:53:14 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_complex_cmd(char *strbase, char *strcomp, int len)
{
	int x;
	int y;
	int base;
	
	x = 0;
	y = 0;
	base = 0;
	char *test;

	test = ft_before_set(strbase, ' ');
//	printf("|%s|\n", test);
	if (ft_strlen(test) != len)
		return(1);
	while (strbase[base] && (strbase[base] == ' ' || strbase[base] == '\n' || strbase[base] == '\t'))
			base++;
	while(strbase[base] && x < len)
	{
		if(strbase[base] == strcomp[x])
			y++;
		x++;
		base++;
	}
	// printf("x: %d, y: %d, len: %d, base:%d\n", x, y, len, base);
	if (x == len && y == x)//(x == len && y == len && y == x)
		return(0);
	else
		return(1);
} // this function checks only the cmd on the line and leaves the rest
