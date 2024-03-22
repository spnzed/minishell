/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:38:05 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/21 16:03:25 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_values_loop(char *cmd, int i, t_info *data, int *simple,
			int *complex)
{
	while (cmd[++i])
	{
		get_quotes_type(cmd[i], simple, complex);
		if (cmd[i] == '<' && cmd[i + 1] != '<'
			&& !*complex && !*simple)
		{
			i++;
			get_value_infile(data, &cmd[i]);
		}
		else if (cmd[i] == '<' && cmd[i + 1] == '<'
			&& !*complex && !*simple)
		{
			i++;
			get_value_heredoc(data, &cmd[i]);
		}
		else if (cmd[i] == '>' && cmd[i + 1] != '>'
			&& !*complex && !*simple)
		{
			i++;
			get_value_outfile(data, &cmd[i], SIMPLE_OUTFILE);
		}
		else if (cmd[i] == '>' && cmd[i + 1] == '>'
			&& !*complex && !*simple)
		{
			i++;
			get_value_outfile(data, &cmd[i], APPEND_OUTFILE);
		}
	}
}

void	get_redirections(char *cmd, t_info *data)
{
	int		simple;
	int		complex;

	simple = 0;
	complex = 0;
	get_values_loop(cmd, -1, data, &simple, &complex);
}
