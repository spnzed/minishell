/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:13:58 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/22 14:46:35 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_var_syntax(char *var)
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
			|| line[i + 1] == '\'' || line[i + 1] == '_') && we_in_quotes == false)
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

int	comprove_var(char *line)
{
	int		i;
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
			|| line[i + 1] == '\'' || line[i + 1] == '_') && we_in_quotes == false)
			return (1);
		else if (line[i] == '$' && (line[i + 1] == '?')
			&& we_in_quotes == false)
			return (1);
	}
	return (0);
}

/*
char	*search_var(char *line)
{
	int		i;
	char	*var;
	bool	we_in_quotes;

	i = -1;
	we_in_quotes = false;
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '\"')
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
*/