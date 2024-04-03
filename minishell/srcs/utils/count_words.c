/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:42:02 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/03 15:51:21 by pquintan         ###   ########.fr       */
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

static void	quotessum(char c, int *simple, int *complex)
{
	if (c == '\'')
		*simple += 1;
	else if (c == '\"')
		*complex += 1;
}

static int	count_quotes(char *str)
{
	int		simple;
	int		complex;

	simple = 0;
	complex = 0;
	int x = 0;
	while (str[x])
	{
		quotessum(str[x], &simple, &complex);
		x++;	
	}
	if ((simple + complex) % 2 == 0)
		return (1);
	return (0);
}

static void	gqt(char c, int *simple, int *complex)
{
	if (c == '\'')
		*simple += 1;
	else if (c == '\"')
		*complex += 1;
	if ((*simple == 2 || *complex == 2) && (*simple == 1 || *complex == 1))
	{
		*simple = 0;
		*complex = 0;
	}
	if (c == '\'' && *simple == 2)
		*simple = 0;
	else if (c == '\"' && *complex == 2)
		*complex = 0;
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
	bool close = count_quotes(str);
	while (str[++i])
	{
		if (close == true)
			get_quotes_type(str[i], &simple, &complex);
		else
			gqt(str[i], &simple, &complex);
		if (ft_isprint(str[i]) && str[i] != ' ' && !simple && !complex)
		{
			count++;
			i = move_to_end(str, i, simple, complex);
		}
	}
	return (count);
}
