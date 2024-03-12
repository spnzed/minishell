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

static void	write_syntax_error(char *cmd, int i)
{
	if (cmd[i + 1] == '|')
	{
		ft_putstr_fd("Minishell: syntax error", 2);
		ft_putstr_fd("Near unexpected token `|'\n", 2);
	}
}

int		cmd_count(char *line)
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
		if (line[i] == '|' && simple == 0 && complex == 0)
		{
			write_syntax_error(line, i);
			count++;
		}
	}
	return (count);
}
