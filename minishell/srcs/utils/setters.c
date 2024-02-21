/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:12:02 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/21 13:07:49 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_after_set(char *str, char set)
{
    int i = 0;
    int x = 0;
	char *dst;

    while (str[i] != '\0' && str[i] != set)
        i++;
    if (str[i] == '\0')
        return ft_strdup("");
    i++;
    dst = (char *)malloc(ft_strlen(str + i) + 1);
    while (str[i] != '\0') {
        dst[x] = str[i];
        i++;
        x++;
    }
    dst[x] = '\0';
    return (dst);
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