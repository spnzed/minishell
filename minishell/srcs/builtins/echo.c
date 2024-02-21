/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/21 15:11:23 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	str_nflag(char *str, int x)
{
	int	i;
	
	x += 2;
	while (str[x] == 'n')
		x++;
	i = x;
	while (str[i])
	{
		if (str[i] == '-' && str[i + 1] == 'n')
		{
			i++;
			while (str[i] == 'n')
				i++;
			x = i;
		}
		i++;
	}
	return(x);
	// basicamente es un '-' y tantas n como quieras
}

int	ft_echo(t_info	*data, char *line, int len)
{
	int x;
	bool n_option;

	x = 4;
	n_option = false;
	if (line[x] == ' ' && line[x + 1] == '-' && line[x + 2] == 'n')
		n_option = true;
	if (n_option == true)
		x = str_nflag(line, x);
	if (len == 4)
		printf("\n");
	else if (len > 4)
	{
		while (line[x] && (line[x] == ' ' || line[x] == '\n' || line[x] == '\t'))
			x++;
		while(line[x])
		{
			while (line[x] && line[x] != ' ' && line[x] != '\n' && line[x] != '\t')
				printf("%c", line[x++]);
			while (line[x] && (line[x] == ' ' || line[x] == '\n' || line[x] == '\t'))
				x++;
			if (line[x + 1])
				printf(" ");
		}
		if (n_option == false)
			printf("\n");
	}
	data->exit_id = 0;
	return(0);
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