/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/05 19:30:12 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *line, int len)
{
	//printf("here: %c%c%c\n", line[4], line[5], line[6]);
	if (len == 4)
		printf("\n");
	else if(line[4] == ' ' && line[5] == '-' && line[6] == 'n' && len == 7)
		printf("");
	else // porque no va este else? // entra solo cuando hago enter sin comando y nose porque
		printf("new\n");
	// check if echo or echo -n
}
/*

	int newline = 1;
	int escape = 0;
	if (echo is the only input)
	{
		printf("\n");
		return(0);
	}
	else if (the cmd input starts with echo)
	{
		if (echo + 1 " " && echo + 2 "-" && echo + 3 is "n") // meaning echo -n
		{
			newline--;
			escape = 1;
		}
		printf("everything after "echo -n "");
		while(newline != 0)
			printf("\n");
		return(0);
	}
	return(1);
*/
// Funcion prototipo

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