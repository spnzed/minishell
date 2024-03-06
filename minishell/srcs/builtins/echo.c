/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/06 16:03:07 by aaespino         ###   ########.fr       */
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

static int	echo_little_cases(char *line, char *HOME, int i)
{
	//printf("%s | %s | %d\n", line, HOME, i);
	if (line[0] == '~')
	{
		printf("%s", HOME);
		if (line[1] == '\0')
			return (i + 1);
		else
			return (i + 99);
	}
    return (i);
}

int	ft_echo(t_info	*data, char **line)
{
	int i;
	int j;
	int n;
	int len;
	char quote;
	char *HOME;
	bool n_option;

	i = 1;
	j = 0;
	n = 0;
	len = ft_arrlen(line);
	n_option = false;
	while (line[i] && str_nflag(line[i]) == true)
	{
		n_option = str_nflag(line[i]);
		i++;
		n++;
	}
	HOME = get_var_list(data->list_env, "HOME")->content + 5;
	if (line[i])
		i = echo_little_cases(line[i], HOME, i);
	else
	{
		if (n_option == false)
			return (printf("\n"), 0);
		else
			return(0);
	}
	if (i > 99)
	{
		i -= 99;
		j++;
	}
	if (i == n + 2 && !line[i])
	{
		if (n_option == false)
			return (printf("\n"), 0);
		else
			return(0);
	}
	while(len > i)
	{
		while (line[i][j] && line[i][j] != ' ' && line[i][j] != '\n' && line[i][j] != '\t')
		{
			if (line[i][j] == '~' && line[i][j - 1] == ' ')
			{
				printf("%s", HOME);
				j++;
			}
			if (line[i][j] == '\"' || line[i][j] == '\'')
			{
				quote = line[i][j];
				j++;
				while (line[i][j] && quote != line[i][j])
					printf("%c", line[i][j++]);
				if (quote == line[i][j]) 
					j++;
			}
			else
				printf("%c", line[i][j++]);
		}
		if (!line[i][j] && i != len - 1)
			printf(" ");
		i++;
		j = 0;
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