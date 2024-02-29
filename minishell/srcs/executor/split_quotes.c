/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:40:44 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/23 18:57:18 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*split_substr_quotes(char *cmd, int start, int end, int count)
{
	int		len;
	char 	*ret_line;

	len = ft_strlen(cmd);
	if (count == 0)
		ret_line = ft_substr(cmd, start, end - start);
	else if ((end + 1) < len)
	{
		if (cmd[end + 1] == ' ')
			ret_line = ft_substr(cmd, start + 1, end - start - 1);
		else
			ret_line = ft_substr(cmd, start + 1, end - 1);
	}
	else
		ret_line = ft_substr(cmd, start + 1, end - start - 1);
	//printf("%s\n", ret_line);
	return (ret_line);
}


static char **put_split_quotes(int words, char *cmd, char **spl)
{
	int	i;
	int	count;
	int	start;

	i = 0;
	count = -1;
	int simple = 0;
	int complex = 0;

	start = 0;
	while (cmd[i] == ' ')
		i++;
	start = i;
	while (cmd[i] && ++count < words)
	{
		if (!ft_isspace(cmd[i]))
		{
			i = get_quote_final(cmd, i, &simple, &complex);
			spl[count] = split_substr_quotes(cmd, start, i, count);
			// spl[count] = ft_strtrim(spl[count], "\'");
			// spl[count] = ft_strtrim(spl[count], "\"");
			while (ft_strlen(cmd) > i && cmd[i + 1] == ' ')
				i++;
			if (!cmd[i])
				return (spl);
			start = i;
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
