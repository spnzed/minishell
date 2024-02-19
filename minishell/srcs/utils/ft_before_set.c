/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:12:02 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/19 15:05:21 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_after_set(char *str, char set)
{
	int		i;
	char 	*dst;
	int		x;

	i = 0;
	x = 0;
	dst = (char *)malloc(sizeof ft_strlen(str) + 1);
	while (set != str[i])
		i++;
	i++;
	while (str[i])
	{
		dst[x] = str[i];
		i++;
		x++;
	}
	dst[i] = '\0';
	return(dst);
}

char	*ft_before_set(char *str, char set)
{
	int				i;
	char 			*dst;

	i = 0;
	while (str[i] && str[i] != set)
		i++;
	dst = (char *)malloc(i + 1);
    int j = 0;
    while (j < i)
    {
        dst[j] = str[j];
        j++;
    }
	dst[i] = '\0';
	return(dst);
}