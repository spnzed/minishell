/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:45:05 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/01 16:34:54 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_start(char *str, int i, int *simple, int *complex)
{
	while ((*simple > 0 || *complex > 0) && str[i] != '|')
	{
		get_quotes_type(str[i], simple, complex);
		i++;
	}
	while (str[i] == '|')
		i++;
	return (i);
}

static int	find_next_pipe(char *str, int i, int *simple, int *complex)
{
	while (str[i])
	{
		if (str[i] == '|' && *simple == 0 && *complex == 0)
			return (i);
		get_quotes_type(str[i], simple, complex);
		i++;
	}
	return (i);
}

static char	*get_split_pipe(char *cmd, int i, int *end)
{
	int		start;
	char	*str;
	int		simple;
	int		complex;

	start = 0;
	simple = 0;
	complex = 0;
	get_quotes_type(cmd[i], &simple, &complex);
	start = find_start(cmd, i, &simple, &complex);
	*end = find_next_pipe(cmd, start, &simple, &complex);
	str = ft_substr(cmd, start, *end - start);
	return (str);
}

char	**split_pipe(t_info *data, char *cmd)
{
	int		i;
	int		j;
	int		end;
	char	**split;

	i = 0;
	j = 0;
	end = 0;
	split = malloc(sizeof(char *) * (cmd_count(data, cmd) + 1));
	if (!split || !cmd)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '|' || i == 0)
		{
			split[j] = get_split_pipe(cmd, i, &end);
			j++;
			i = end - 1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
