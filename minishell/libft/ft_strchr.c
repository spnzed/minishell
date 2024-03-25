/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:18:25 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/25 14:44:20 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == (char )c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char )c)
		return (&str[i]);
	return (NULL);
}
