/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:12:02 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/15 17:47:53 by pquintan         ###   ########.fr       */
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
	dst = (char *)malloc(sizeof ft_strlen(str) + 1);
	while (str[i])
	{
		if (set == str[i])
			break ;
		else
		{
			dst[i] = str[i];
			i++;
		}
	}
	dst[i] = '\0';
	return(dst);
}
	
	// size_t	start;
	// size_t	len;

	// start = 0;
	// len = ft_strlen(s1);
	// while (s1[start] && ft_strchr (set, s1[start]))
	// 	start++;
	// while (len && ft_strrchr (set, s1[len]))
	// 	len--;
	// return (ft_substr (s1, start, (len - start) + 1));

// una funcion que te devuelve la string antes de x caracteres