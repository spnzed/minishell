/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:04:23 by aaespino          #+#    #+#             */
/*   Updated: 2022/02/02 14:57:02 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned int	string;

	str = (char *)s;
	string = ft_strlen(str);
	if (!s)
		return (NULL);
	if ((char )c == '\0')
		return (&str[string]);
	while (string--)
	{
		if (str[string] == (char )c)
			return (&str[string]);
	}
	return (NULL);
}
