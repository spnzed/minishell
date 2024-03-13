/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:38:05 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/14 17:43:34 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i]) // Mientras haya caracteres en ambas cadenas
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]); // + swap
	}
	// Si una cadena es más larga que la otra, devuelve la diferencia de longitud
	return (s1[i] - s2[i]);
}
