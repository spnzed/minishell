/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/26 16:26:24 by pquintan         ###   ########.fr       */
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
	return(true);
}

int	ft_echo(t_info	*data, char **line)
{
	int i;
	int j;
	
	bool n_option;

	// i = 0;
	// while (line[i++])
	// 	printf("%d: %s\n", i, line[i]);
	i = 1;
	j = 0;
	if (!line[i])
		return (printf("\n"), 0);
	n_option = str_nflag(line[i]);
	if (n_option)
		i++;
	while (line[i][j] && (line[i][j] == ' ' || line[i][j] == '\n' || line[i][j] == '\t'))
		j++;
	while(line[i][j])
	{
		while (line[i][j] && line[i][j] != ' ' && line[i][j] != '\n' && line[i][j] != '\t')
		{
			if (line[i][j] == '\"' || line[i][j] == '\'')
				j++;
			else
				printf("%c", line[i][j++]);
		}
		while (line[i][j] && (line[i][j] == ' ' || line[i][j] == '\n' || line[i][j] == '\t'))
			j++;
		if (line[i][j + 1])
			printf(" ");
	}
	if (n_option == false)
		printf("\n");
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