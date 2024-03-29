/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:42:02 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/22 11:46:05 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	move_to_end(char *str, int i, int simple, int complex)
{
	while ((ft_isprint(str[i]) && str[i] != ' ') && (!simple && !complex)
		&& str[i + 1])
	{
		i++;
		get_quotes_type(str[i], &simple, &complex);
		if (simple)
		{
			while (simple && str[i])
			{
				i++;
				get_quotes_type(str[i], &simple, &complex);
			}
		}
		else if (complex)
		{
			while (complex && str[i])
			{
				i++;
				get_quotes_type(str[i], &simple, &complex);
			}
		}
	}
	return (i);
}

int	count_words(char *str)
{
	int		i;
	int		count;
	int		simple;
	int		complex;

	i = -1;
	count = 0;
	simple = 0;
	complex = 0;
	while (str[++i])
	{
		get_quotes_type(str[i], &simple, &complex);
		if (ft_isprint(str[i]) && str[i] != ' ' && !simple && !complex)
		{
			count++;
			i = move_to_end(str, i, simple, complex);
		}
	}
	return (count);
}
