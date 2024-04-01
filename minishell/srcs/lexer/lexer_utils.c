/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:56:17 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/01 14:20:59 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	free_and_return(t_info *data)
{
	put_error_prev(data, 0, "syntax error near unexpected token `<'\n", 2);
	return (2);
}

int	redir_syntax(char *line, t_info *data)
{
	int	i;
	int	simple;
	int	complex;

	i = -1;
	simple = 0;
	complex = 0;
	while (line[++i])
	{
		if (line[i] == '>' && line[i + 1] == '<')
			return (free_and_return(data));
		if (line[i] == '<' && line[i + 1] == '<' && line[i + 2] == '<')
			return (free_and_return(data));
		if (line[i] == '>' && line[i + 1] == '>' && line[i + 2] == '>')
			return (free_and_return(data));
		if (line[i] == '\'' || line[i] == '\"')
			get_quotes_type(line[i], &simple, &complex);
		if (get_redir_syntax_values (data, line[i], &simple, &complex))
			return (2);
	}
	if (get_redir_end(line, data))
		return (1);
	return (0);
}

/*
La función strpbrk() es una función estándar en C que se utiliza
 para buscar 
la primera ocurrencia de cualquiera de los caracteres en una cadena
 dada y devuelve 
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
