/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:44:07 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/11 18:04:09 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*alloc_final_line(char *replacer, char *before_val, char *after_val)
{
	char	*final_line;

	if (ft_strlen(replacer))
	{
		final_line = ft_strjoin(before_val, replacer);
		final_line = ft_strjoin(final_line, after_val);
	}
	else
	{
		if (ft_strlen(after_val))
			final_line = ft_strjoin(before_val, after_val);
		else
		{
			free(after_val);
			return (before_val);
		}
	}
	free(after_val);
	free(before_val);
	return (final_line);
}

char	*put_variable(char *line, char *var, char *replace)
{
	int			len_before_var;
	int			final_position;
	char		*str_before_var;
	char		*str_after_var;
	char		*final_line;

	final_line = 0;
	len_before_var = ft_strlen(line) - ft_strlen(search_var(line));
	final_position = len_before_var + ft_strlen(var) + 1;
	str_before_var = ft_substr(line, 0, len_before_var);
	str_after_var = ft_substr(line, final_position,
			(ft_strlen(search_var(line) + ft_strlen(var))));
	final_line = alloc_final_line(replace, str_before_var, str_after_var);
	return (final_line);
}
