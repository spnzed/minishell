/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:56:17 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/22 18:41:57 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (get_redir_end(line))
		return (1);
	return (0);
}

/*
La función strpbrk() es una función estándar en C que se utiliza para buscar 
la primera ocurrencia de cualquiera de los caracteres en una cadena dada y devuelve 
un puntero a esa posición en la cadena.
*/
char	*export_id(char *var)
{
	int		i;
	char	*res;
	char	*found;
	char	*non_alnum;

	i = 0;
	if (*var == '$')
		var++;
	if (*var == '?')
		return ("?");
	non_alnum = ft_strdup(" \'\"!#$%%&\\()*+,-./:;<=>@[]^`{|}~");
	found = ft_strpbrk(var, non_alnum);
	free(non_alnum);
	if (!found)
		res = ft_strdup(var);
	else
		res = ft_substr(var, 0, found - var);
	return (res);
}

