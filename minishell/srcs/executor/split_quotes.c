/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:05:00 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/01 16:17:53 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*split_substr_quotes(char *cmd, int start, int end, int count)
{
	int		len;
	char	*ret_line;

	len = ft_strlen(cmd);
	if (count == 0)
		ret_line = ft_substr(cmd, start, end - start);
	else if ((end + 1) < len)
		ret_line = ft_substr(cmd, start + 1, end - start - 1);
	else
	{
		if (cmd[start] == '\'' || cmd[start] == '\"')
			ret_line = ft_substr(cmd, start + 2, end - start - 2);
		ret_line = ft_substr(cmd, start + 1, end - start - 1);
	}
	return (ret_line);
}

static void	cmd_treatment(char *cmd, char **spl, int *i, t_info *data)
{
	int	simple;
	int	complex;

	simple = 0;
	complex = 0;
	while (cmd[*i] && cmd[*i] != ' ' && cmd[*i] != '\'' && cmd[*i] != '\"')
		(*i)++;
	get_quotes_type(cmd[*i], &simple, &complex);
	if (simple || complex)
		*i = get_quote_final(cmd, *i, &simple, &complex);
	spl[data->count] = split_substr_quotes(cmd, data->start, *i, data->count);
	while (ft_strlen(cmd) > *i && cmd[*i + 1] == ' ')
		(*i)++;
	data->start = *i;
}

static char	**put_split_quotes(int words, char *cmd, char **spl)
{
	int		i;
	t_info	data;

	i = 0;
	data.count = 0;
	data.start = 0;
	while (cmd[i] == ' ')
		i++;
	data.start = i;
	while (cmd[i] && data.count < words)
	{
		if (!ft_isspace(cmd[i]))
		{
			cmd_treatment(cmd, spl, &i, &data);
			if (!cmd[i])
				return (spl);
		}
		i++;
		data.count++;
	}
	return (spl);
}

char	**split_quotes(char *cmd)
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
