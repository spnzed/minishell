/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/08 17:43:10 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	echo_little_cases(char *line, char *HOME, int i)
{
	if (line[0] == '~')
	{
		if (line[1] == ' ' || line[1] == '\0' || line[1] == '/')
			printf("%s", HOME);
		else
			printf("~");
		if (line[1] == '\0')
			return (i + 1);
		else
			return (i + 99);
	}
	return (i);
}

static int	ft_n_option(t_info *data, char **line, t_echo *e)
{
	part_one(line, e);
	if (line[e->i])
		e->i = echo_little_cases(line[e->i], data->home, e->i);
	else
	{
		if (e->n_option == false)
			return (1);
		else
			return (0);
	}
	if (e->i > 99)
	{
		e->i -= 99;
		e->j++;
	}
	if (e->i == e->n + 2 && !line[e->i])
	{
		if (e->n_option == false)
			return (1);
		else
			return (0);
	}
	return (2);
}

int	echo_builtin(t_info	*data, char **line)
{
	t_echo	e;
	int		res;

	e.n_option = NULL;
	data->exit_id = 0;
	res = ft_n_option(data, line, &e);
	if (res == 1)
		return (printf("\n"), 0);
	else if (res == 0)
		return (0);
	while (e.len > e.i)
	{
		loop_one(line, &e, data);
		if (!line[e.i][e.j] && e.i != e.len - 1)
			printf(" ");
		e.i++;
		e.j = 0;
	}
	if (e.n_option == false)
		printf("\n");
	return (0);
}
