/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:44:07 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/22 11:42:03 by pquintan         ###   ########.fr       */
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
	t_var	s;
	char	*final_line;

	final_line = 0;
	s.len_var = ft_strlen(var);
	s.len_before_var = ft_strlen(line) - ft_strlen(search_var(line));
	s.len_after_var = ft_strlen(search_var(line) + s.len_var);
	s.final_position = s.len_before_var + s.len_var + 1;
	s.str_before_var = ft_substr(line, 0, s.len_before_var);
	s.str_after_var = ft_substr(line, s.final_position, s.len_after_var);
	final_line = alloc_final_line(replace, s.str_before_var, s.str_after_var);
	return (final_line);
}
