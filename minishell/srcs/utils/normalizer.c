/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:48:18 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/01 15:28:13 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	loop(char *str, char *normal, int i, int y)
{
	int	x;

	x = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t')
			&& (str[i + 1] == ' ' || str[i + 1] == '\t'))
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
}

char	*normalizer(char *str)
{
	char	*normal;
	int		i;
	int		y;
	int		len;

	normal = " ";
	if (!str)
		return (normal);
	len = ft_strlen(str);
	normal = malloc(sizeof(char) * (len + 1));
	i = 0;
	y = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	loop(str, normal, i, y);
	normal[y] = '\0';
	return (normal);
}
