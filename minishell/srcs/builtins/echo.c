/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/12 17:53:50 by pquintan         ###   ########.fr       */
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

static int	echo_home(char *line, char *HOME, int i)
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

static int	echo_prev_one(t_info *data, t_echo e, char **line)
{
	while (line[e.i] && str_nflag(line[e.i]) == true)
	{
		e.n_option = str_nflag(line[e.i]);
		e.i++;
		e.n++;
	}
	if (line[e.i])
		e.i = echo_home(line[e.i], data->home, e.i);
	else
	{
		if (e.n_option == false)
			return(2);
		else
			return (0);
	}
	if (e.i > 99)
	{
		e.i -= 99;
		e.j++;
	}
	if (e.i == e.n + 2 && !line[e.i])
	{
		if (e.n_option == false)
			return (2);
		else
			return (0);
	}
	return (1);
}

int	ft_echo(t_info	*data, char **line)
{
	t_echo	e;

	e.i = 1;
	e.j = 0;
	e.n = 0;
	e.len = ft_arrlen(line);
	e.n_option = false;
	if (echo_prev_one(data, e, line) == 0)
		return (0);
	else if (echo_prev_one(data, e, line) == 2)
		return (printf("\n"), 0);
	// while (line[e.i] && str_nflag(line[e.i]) == true)
	// {
	// 	e.n_option = str_nflag(line[e.i]);
	// 	e.i++;
	// 	e.n++;
	// }
	// if (line[e.i])
	// 	e.i = echo_home(line[e.i], data->home, e.i);
	// else
	// {
	// 	if (e.n_option == false)
	// 		return (printf("\n"), 0);
	// 	else
	// 		return (0);
	// }
	// if (e.i > 99)
	// {
	// 	e.i -= 99;
	// 	e.j++;
	// }
	// if (e.i == e.n + 2 && !line[e.i])
	// {
	// 	if (e.n_option == false)
	// 		return (printf("\n"), 0);
	// 	else
	// 		return (0);
	// }
	while (e.len > e.i)
	{
		while (line[e.i][e.j] && line[e.i][e.j] != ' ' && line[e.i][e.j] != '\n'
				&& line[e.i][e.j] != '\t')
		{
			if (line[e.i][e.j] == '~' && line[e.i][e.j - 1] == ' ')
			{
				printf("%s", data->home);
				e.j++;
			}
			if (line[e.i][e.j] == '\"' || line[e.i][e.j] == '\'')
			{
				e.quote = line[e.i][e.j];
				e.j++;
				while (line[e.i][e.j] && e.quote != line[e.i][e.j])
					printf("%c", line[e.i][e.j++]);
				if (e.quote == line[e.i][e.j])
					e.j++;
			}
			else
				printf("%c", line[e.i][e.j++]);
		}
		if (!line[e.i][e.j] && e.i != e.len - 1)
			printf(" ");
		e.i++;
		e.j = 0;
	}
	if (e.n_option == false)
		printf("\n");
	data->exit_id = 0;
	return (0);
}

/*
bash-3.2$ echo -nn hi
hibash-3.2$

bash-3.2$ echo -n -n hi
hibash-3.2$

-----------------------------
42-Minishell ~ % echo -nn hi
n hi42-Minishell ~ %

42-Minishell ~ % echo -n -n hi
-n hi42-Minishell ~ %
*/

// EXAMPLES OF ECHO 

/*
bash-3.2$ echo -> only echo, does a double new line

bash-3.2$ echo -n -> only echo -n, a new line
bash-3.2$ echo "hola" -n -> if "-n" is after the echo input counts as an input
hola -n
bash-3.2$ echo -n "hola" -> if "-n" is before echo input but after "echo"
it counts as an escape sequence and skips the new line
holabash-3.2$ echo "hola" -> this is the traditional use of "echo" input and newline
hola
bash-3.2$
bash-3.2$ echo "'hola'" -> parser things
'hola'
*/