/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:54:42 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/01 14:19:44 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int quotes_syntax(char *line)
{
	int i;
	int simple;
	int	complex;

	i = -1;
	simple = 0;
	complex = 0;
	if (!ft_strlen(line))
		return (1);
	while (line[++i])
	{
		if ((line[i] == '\'') && (complex == 0 || (complex == 0 && simple != 0)))
			simple++;
		else if ((line[i] == '\"') && (simple % 2 == 0 
			|| (simple == 0 && complex != 0)))
			complex++;
	}
	if ((simple == 0 && complex % 2 == 0)
		|| (simple % 2 == 0 && complex == 0)
		|| (simple % 2 == 0 && complex % 2 == 0 ))
		return (0);
	else
		return (1);
}

int pipe_syntax(char *line)
{
	int	size;

	size = ft_strlen(line) - 1;
	if (line[0] == '|')
	{
		ft_putstr_fd("Syntax error: Unexpected token '|'\n", 2);
		return (1);
	}
	if (line[size] == '|')
	{
		ft_putstr_fd("pipe>\n", 2);
		return (1);
	}
	return (0);
}

int	redir_syntax(char *line)
{
	int	i;
	int	simple;
	int	complex;
	int	r_left;
	int	r_right;

	i = -1;
	simple = 0;
	complex = 0;
	r_left = 0;
	r_right = 0;
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			get_quotes_type(line[i], &simple, &complex);
		if (get_redir_syntax_values (line[i], &simple, &complex, &r_left, &r_right))
			return (1);
	}
	if (check_redir_ends(line))
		return (1);
	return (0);
}

int	syntax_error(t_info *data)
{
	if (quotes_syntax(data->cmd_line))
		return(free(data->cmd_line), write(2, "quote>\n", 8));
	if (pipe_syntax(data->cmd_line) && data->cmd_nbr > 1)
		return(free(data->cmd_line), 1);
	if (redir_syntax(data->cmd_line) && (ft_strchr(data->cmd_line, '>')
		|| ft_strchr(data->cmd_line, '<')))
		return(free(data->cmd_line), 1);
	return(0);
}
