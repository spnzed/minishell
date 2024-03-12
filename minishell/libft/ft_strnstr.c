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

char	*ft_strnstr(const char *haystack, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (((char *)ndl)[i] == '\0')
		return (&((char *)haystack)[i]);
	while (((char *)haystack)[i] && i < len)
	{
		k = i;
		while (((char *)haystack)[k] == ((char *)ndl)[j] &&
		((char *)haystack)[k] != '\0' && ((char *)ndl)[j] != '\0' &&
		k < len)
		{
			k++;
			j++;
		}
		if (((char *)ndl)[j] == '\0')
			return (&((char *)haystack)[i]);
		j = 0;
		i++;
	}
	return (0);
}
