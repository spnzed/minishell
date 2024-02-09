/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:02:17 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/09 15:02:28 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_first_word(char *str)
{
	int x;
	char *str_copy;
	int len;

	x = 0;
	len = ft_strlen(str);
	str_copy = (char *)malloc(len + 1);
	while (str[x] && (str[x] == ' ' || str[x] == '\t'))
		x++;
	while (str[x] && str[x] != ' ' && str[x] != '\t')
	{
		str_copy[x] = str[x];
		x++;
	}
	str_copy[x] = '\0';
	return(str_copy);
}
