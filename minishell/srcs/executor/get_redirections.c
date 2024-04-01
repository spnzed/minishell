/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:38:05 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/01 15:24:55 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_values_loop(char *cmd, int i, t_info *data)
{
	int		simple;
	int		complex;

	simple = 0;
	complex = 0;
	while (cmd[++i])
	{
		get_quotes_type(cmd[i], &simple, &complex);
		if (cmd[i] == '<' && cmd[i + 1] != '<'
			&& !complex && !simple)
			get_value_infile(data, &cmd[i++]);
		else if (cmd[i] == '<' && cmd[i + 1] == '<'
			&& !complex && !simple)
			get_value_heredoc(data, &cmd[++i]);
		else if (cmd[i] == '>' && cmd[i + 1] != '>'
			&& !complex && !simple)
			get_value_outfile(data, &cmd[++i], SIMPLE_OUTFILE);
		else if (cmd[i] == '>' && cmd[i + 1] == '>'
			&& !complex && !simple)
			get_value_outfile(data, &cmd[++i], APPEND_OUTFILE);
	}
}

void	get_redirections(char *cmd, t_info *data)
{
	get_values_loop(cmd, -1, data);
}
