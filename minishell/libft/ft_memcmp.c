/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:27:40 by aaespino          #+#    #+#             */
/*   Updated: 2022/01/25 20:22:31 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*auxs1;
	unsigned char	*auxs2;

	i = 0;
	auxs1 = (unsigned char *)s1;
	auxs2 = (unsigned char *)s2;
	while (i < n)
	{
		if (auxs1[i] != auxs2[i])
			return (auxs1[i] - auxs2[i]);
		else
			i++;
	}
	return (0);
}
