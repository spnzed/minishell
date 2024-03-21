/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:26:56 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/21 15:30:55 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = (int)ft_strlen(s1);
	if (n > size)
		n = size;
	str = malloc(sizeof(char) * (n + 1));
	if (!str)
	{
		ft_putstr_fd("Malloc failure\n", 1);
		return (NULL);
	}
	while (i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
