/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:40:24 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/22 14:24:47 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_end_redir(char *str, int i)
{
	int		simple;
	int		complex;

	simple = 0;
	complex = 0;
	while (str[i])
	{
		while (str[i] == '<' || str[i] == '>')
			i++;
		while (str[i] == ' ')
			i++;
		while (!ft_isspace(str[i]) && str[i + 1] != '\0')
		{
			get_quotes_type(str[i], &simple, &complex);
			i++;
		}
		while (str[i] == ' ' && str[i + 1] != '\0')
			i++;
		if (str[i + 1] == '\0')
			return (i + 1);
		if (str[i] == '<' || str[i] == '>')
			i++;
		else
		{
			if (!simple && !complex)
				return (i);
			else
				i++;
		}
	}
	return (i);
}

static char	*remove_redir(char *str, int pos)
{
	int		len;
	int		end;
	char	*clean;
	char	*before_redir;
	char	*after_redir;

	len = ft_strlen(str);
	end = get_end_redir(str, pos);
	if (str[end - 1] == ' ')
		end--;
	if (pos == 0)
		clean = ft_substr(str, end, len);
	else if (len == end)
		clean = ft_substr(str, 0, pos);
	else
	{
		before_redir = ft_substr(str, 0, pos);
		after_redir = ft_substr(str, end, len);
		clean = ft_strjoin(before_redir, after_redir);
		free(before_redir);
		free(after_redir);
	}
	if (str)
		free(str);
	return (clean);
}

char	*clean_redir(char *str)
{
	int		i;
	int		simple;
	int		complex;
	char	*clean;

	i = -1;
	simple = 0;
	complex = 0;
	clean = ft_strdup(str);
	while (clean[++i])
	{
		get_quotes_type(clean[i], &simple, &complex);
		if ((clean[i] == '<' || clean[i] == '>' ) && !simple && !complex)
		{
			clean = remove_redir(clean, i);
			i = -1;
		}
	}
	return (clean);
}
