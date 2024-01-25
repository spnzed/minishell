/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:30:06 by aaespino          #+#    #+#             */
/*   Updated: 2023/04/26 17:27:43 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_w(const char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	trigger;

	i = 0;
	count = 0;
	trigger = 0;
	while (s[i])
	{
		if (s[i] != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (s[i] == c)
			trigger = 0;
		i++;
	}
	return (count);
}

char	*write_w(const char *str, int start, int end)
{
	size_t	i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

void	put_w(char **array, const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		activador;

	i = 0;
	j = 0;
	activador = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && activador < 0)
			activador = i;
		else if ((s[i] == c || i == ft_strlen(s)) && activador >= 0)
		{
			array[j++] = write_w(s, activador, i);
			activador = -1;
		}
		i++;
	}
	array[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (0);
	array = malloc(sizeof(char *) * (count_w(s, c) + 1));
	if (!array)
		return (0);
	put_w(array, s, c);
	return (array);
}
