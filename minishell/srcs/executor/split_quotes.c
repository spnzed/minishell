/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:40:44 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/15 19:25:14 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
    - [ ]  put_split_quotes
        - [ ]  get_final_quote
        - [ ]  substr_split_quotes
    - [ ]  clean_split
        - [ ]  array_size
        - [ ]  size_word
        - [ ]  copy_word
*/

static char **put_split_quotes(int size, char *cmd, char **spl, int simple, int complex)
{
	int	i;
	int	j;
	int	start;

	i = -1;
	j = -1;
	start = 0;
	while (cmd[++i] == ' ')
		;
	start = i;
	i--;
	while (cmd[++i] && ++j < size)
	{
		if (!ft_isspace(cmd[i]))
		{
			i = get_quote_final(cmd, i, simple, complex);
			spl[j] = split_substr_quotes(cmd, i, start, j);
			i--;
			while ((int)ft_strlen(cmd) > ++i && cmd[i + 1] == ' ')
				;
			if (!cmd[i])
				return (spl);
			start = i;
		}
	}
	return (spl);
}

char **split_quotes(char *cmd)
{
	int		size;
	char	**split;
	int		simple;
	int		complex;

	simple = 0;
	complex = 0;

	size = count_words(cmd) + 1;
	split = malloc(sizeof(char *) * (size));
	if (!split)
		return (NULL);
	split[size] = NULL;
	split = put_split_quotes(size, cmd, split, simple, complex);
	return (split);
}
