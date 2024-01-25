/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:38:14 by aaespino          #+#    #+#             */
/*   Updated: 2022/02/02 17:32:42 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	start = 0;
	len = ft_strlen(s1);
	while (s1[start] && ft_strchr (set, s1[start]))
		start++;
	while (len && ft_strrchr (set, s1[len]))
		len--;
	return (ft_substr (s1, start, (len - start) + 1));
}
