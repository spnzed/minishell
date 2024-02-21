/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:45:05 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/21 18:20:01 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int find_start(char *str, int i, char c, int *simple, int *complex)
{
	while ((*simple > 0 || *complex > 0) && str[i] != c)
	{
		get_quotes_type(str[i], simple, complex);
		i++;
	}
	while (str[i] == c)
		i++;
	return(i);
}

static int find_next_pipe(char *str, int i, char c, int *simple, int *complex)
{
	while (str[i])
	{
		if (str[i] == c && *simple == 0 && *complex == 0)
			return (i);
		get_quotes_type(str[i], simple, complex);
		i++;
	}
	return (i);
}

char	**split_pipe(char *cmd, char c)
{
	int		i;
	int		j;
	int		start;
	int		end;
	int		cmd_nbr;
	char 	**split;
	int		simple;
	int		complex;

	i = 0;
	j = 0;
	start = 0;
	end = 0;
	simple = 0;
	complex = 0;

	cmd_nbr = cmd_count(cmd);
	split = malloc(sizeof(char *) * (cmd_nbr + 1));
	if (!split || !cmd)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == c || i == 0)
		{
			start = find_start(cmd, i, '|', &simple, &complex);
			end = find_next_pipe(cmd, start, '|', &simple, &complex);
			split[j] = ft_substr(cmd, start, end - start);
			j++;
			i = end - 1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
