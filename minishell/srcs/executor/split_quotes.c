/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:40:44 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/23 13:01:11 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char **put_split_quotes(int words, char *cmd, char **spl)
{
	int	i;
	int	count;
	int	start;

	i = 0;
	count = -1;
	// int simple = 0;
	// int complex = 0;

	start = 0;
	while (cmd[i] == ' ')
		i++;
	start = i;
	while (cmd[i] && ++count < words)
	{
		start = i;
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			while (cmd[i] == '\'' || cmd[i] == '\"')
				i++;
			start = i;
		}
		while (ft_isspace(cmd[i]))
			i++;
		if (!ft_isspace(cmd[i]))
		{
			i = get_quote_final(cmd, i);
			spl[count] = split_substr_quotes(cmd, start, i, count);
			spl[count] = ft_strtrim(spl[count], " ");
			while ((int)ft_strlen(cmd) > i && cmd[i + 1] == ' ')
				i++;
			if (!cmd[i])
				return (spl);
		}
		i++;
	}
	return (spl);
}

char **split_quotes(char *cmd)
{
	int		words;
	char	**split;

	words = count_words(cmd);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split[words] = NULL;
	split = put_split_quotes(words, cmd, split);
	return (split);
}
