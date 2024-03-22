/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:48:18 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/22 12:19:00 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char 	*normalizer(char *str)// takes a string and puts all in lower and without more than one space
{
	char *normal;
	int i;
	int y;
	int len;
	int x;
	
	normal = " ";
	if (!str)
		return(normal);
	len = ft_strlen(str);
	normal = malloc(sizeof(char) * (len + 1));
	i = 0;
	y = 0;
	x = 0;
	while (str[i] == ' ' || str[i] == '\t')
			i++;
	while(str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && (str[i + 1] == ' ' || str[i + 1] == '\t'))
		 	i++;
		if (str[i] == ' ' || str[i] == '\t')
			x = 1;
		if (x == 0 && str[i] >= 'A' && str[i] <= 'Z')
			normal[y] = str[i] + 32;
		else
			normal[y] = str[i];
		y++;
		i++;
	}
	normal[y] = '\0';
	return(normal);
}
