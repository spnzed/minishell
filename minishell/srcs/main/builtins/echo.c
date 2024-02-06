/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/06 16:19:27 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *line, int len)
{
	int x;
	bool n_option;

	x = 4;
	n_option = false;
	if (line[x] == ' ' && line[x + 1] == '-' && line[x + 2] == 'n')
		n_option = true;
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
			printf(" ");
		}
		if (n_option == false)
			printf("\n");
	}
}

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