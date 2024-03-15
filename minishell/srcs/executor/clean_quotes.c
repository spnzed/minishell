/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:40:24 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/15 18:01:54 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int num_quotes(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			count++;
	}
	return (count);
}

static char	*str_wo_quotes(char *s1)
{
	size_t	i;
	size_t	j;
	int 	count;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	count = num_quotes(s1);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1 - count));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		if (s1[i] != '\"' && s1[i] != '\'')
		{
			str[j] = s1[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}


char	*clean_quotes(char *str)
{
	int		i;
	char	*clean;
	char	*ret;

	i = -1;
	clean = ft_strtrim(str, "\'");
	clean = ft_strtrim(clean, "\"");
	ret = str_wo_quotes(clean);
	return (ret);
}
