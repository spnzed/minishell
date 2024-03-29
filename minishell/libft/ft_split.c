/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:30:06 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/22 12:44:10 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_w(const char *s, char c)
{
	int	i;
	int	count;
	int	trigger;

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
	int		i;
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
	int	i;
	int	j;
	int	activador;
	int	len;

	i = 0;
	j = 0;
	activador = -1;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] != c && activador < 0)
			activador = i;
		else if ((s[i] == c || i == len) && activador >= 0)
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
		return (NULL);
	array = malloc(sizeof(char *) * (count_w(s, c) + 1));
	if (!array)
		return (NULL);
	put_w(array, s, c);
	return (array);
}
