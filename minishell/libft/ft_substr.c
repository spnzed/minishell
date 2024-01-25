/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:18:27 by aaespino          #+#    #+#             */
/*   Updated: 2022/02/01 17:57:53 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*reserva;
	size_t	aux;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	aux = 0;
	if (len > slen)
		reserva = malloc (sizeof(char) * slen + 1);
	else
		reserva = malloc (sizeof(char) * len + 1);
	if (!reserva)
		return (NULL);
	if (start < slen)
		while (aux < len && s[start] != '\0')
			reserva[aux++] = s[start++];
	reserva[aux] = '\0';
	return (reserva);
}
