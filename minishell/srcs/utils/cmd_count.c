/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:39:01 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 18:43:16 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_cmd_error(t_info *data, char *cmd, int i)
{
	int aux;

	aux = i;
	if (cmd[i + 1] == ' ')
	{
		i++;
		while (ft_isspace(cmd[i]))
		{
			if (cmd[i + 1] == '|')
			{
				put_error_prev(data, 0, " : syntax error near unexpected token `|'\n", 2);
				return(1);
			}
			i++;
		}
	}
	i = aux;
	if (cmd[i + 1] == '|' && cmd[i + 2] == '|')
	{
		put_error_prev(data, 0, " : syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	return (0);
}

int		cmd_count(t_info *data, char *line)
{
	int i;
	int count;
	int simple;
	int	complex;

	i = -1;
	count = 1;
	simple = 0;
	complex = 0;
	if (!line[0])
		return (0);
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			get_quotes_type(line[i], &simple, &complex);
		if (line[i + 1] == '|' && line[i + 2] == ' ')
			i++;
		if (line[i] == '|' && !simple && !complex)
		{
			if (check_cmd_error(data, line, i))
				return (42);
			count++;
		}
	}
	return (count);
}
