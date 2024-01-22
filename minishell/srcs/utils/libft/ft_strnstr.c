/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:00:15 by marvin            #+#    #+#             */
/*   Updated: 2022/01/28 17:00:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (((char *)needle)[i] == '\0')
		return (&((char *)haystack)[i]);
	while (((char *)haystack)[i] && i < len)
	{
		k = i;
		while (((char *)haystack)[k] == ((char *)needle)[j] &&
		((char *)haystack)[k] != '\0' && ((char *)needle)[j] != '\0' &&
		k < len)
		{
			k++;
			j++;
		}
		if (((char *)needle)[j] == '\0')
			return (&((char *)haystack)[i]);
		j = 0;
		i++;
	}
	return (0);
}
