/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/06 12:12:14 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *line, int len)
{
	int x;

	x = 4;
	if (len == 4)
		printf("\n"); // only echo
	else if(line[4] == ' ' && line[5] == '-' && line[6] == 'n' && len == 7)
		printf("");
	else if (len > 4) //echo normal
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
		printf("\n");
	}
	//printf("line: %s\n", line);
//	else if () // porque no va este else? // entra solo cuando hago enter sin comando y nose porque
//		printf("after -n without spaces\n");
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