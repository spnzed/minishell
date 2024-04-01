/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/01 13:54:16 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	bool	str_nflag(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	else
		return (false);
	if (str[i] == 'n')
		while (str[i] == 'n')
			i++;
	else
		return (false);
	return (true);
}

void	part_one(char **line, t_echo *e)
{
	e->i = 1;
	e->j = 0;
	e->n = 0;
	e->len = ft_arrlen(line);
	while (line[e->i] && str_nflag(line[e->i]) == true)
	{
		e->n_option = str_nflag(line[e->i]);
		e->i++;
		e->n++;
	}
}

void	loop_one(char **line, t_echo *e, t_info *data)
{
	while (line[e->i][e->j] && line[e->i][e->j] != ' ' &&
		line[e->i][e->j] != '\n' && line[e->i][e->j] != '\t')
	{
		if (line[e->i][e->j] == '~' && line[e->i][e->j - 1] == ' ')
		{
			printf("%s", data->home);
			e->j++;
		}
		if (line[e->i][e->j] == '\"' || line[e->i][e->j] == '\'')
		{
			e->quote = line[e->i][e->j];
			e->j++;
			while (line[e->i][e->j] && e->quote != line[e->i][e->j])
				printf("%c", line[e->i][e->j++]);
			if (e->quote == line[e->i][e->j])
				e->j++;
		}
		else
			printf("%c", line[e->i][e->j++]);
	}
}
