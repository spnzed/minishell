/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:13:58 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/01 18:45:35 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	check_var_syntax(char *var)
{
	int	i;

	i = 0;
	if (ft_isdigit(var[i]))
		return (0);
	while (var[i])
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

char	*search_var(char *line)
{
	int		i;
	char	*var;
	bool	we_in_quotes;

	i = -1;
	we_in_quotes = false;
	while (line[++i])
	{
		if (line[i] == '\'')
		{
			if (we_in_quotes == true)
				we_in_quotes = false;
			else
				we_in_quotes = true;
		}
		if (line[i] == '$' && (ft_isalnum(line[i + 1]) 
			|| line[i + 1] == '\'' || line[i + 1] == '\"'
			|| line[i + 1] == '_') && we_in_quotes == false)
		{
			var = export_id(&line[i + 1]);
			check_var_syntax(var);
			free(var);
			return (&line[i]);
		}
		else if (line[i] == '$' && (line[i + 1] == '?')
			&& we_in_quotes == false)
			return (&line[i]);
	}
	return (NULL);
}
