/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:48:19 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/07 14:43:06 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char 	*ft_normal(char *str)// takes a string and puts all in lower and without more than one space
{
	char *normal;
	int i;
	int y;
	int len;

	len = ft_strlen(str);
	normal = (char *)malloc(len + 1);
	i = 0;
	y = 0;
	if ((str[i] == ' ' || str[i] == '\t') && i == 0)
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	while(str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && (str[i + 1] == ' ' || str[i + 1] == '\t'))
			i++;
		if ((str[i] == ' ' || str[i] == '\t') && !(str[i + 1]))
			i++;
		if (str[i] >= 'A' && str[i] <= 'Z')
			normal[y] = str[i] + 32;
		else
			normal[y] = str[i];
		y++;
		i++;
	}
	normal[y] = '\0';
	//printf("normal:%s, str:%s\n", normal, str);
	return(normal);
}

int	ft_check_complex_cmd(char *strbase, char *strcomp, int len)
{
	int x;
	int y;
	int base;
	
	x = 0;
	y = 0;
	base = 0;
	while (strbase[base] && (strbase[base] == ' ' || strbase[base] == '\n' || strbase[base] == '\t'))
			base++;
	while(strbase[base] && x < len)
	{
		if(strbase[base] == strcomp[x])
			y++;
		x++;
		base++;
	}
	//printf("x: %d, y: %d, len: %d, base:%d\n", x, y, len, base);
	if (x == len && y == x)//(x == len && y == len && y == x)
		return(0);
	else
		return(1);
} // this function checks only the cmd on the line and leaves the rest
