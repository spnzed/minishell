/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:40:44 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 12:29:19 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*loop_ret(int simple, int complex, char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		get_quotes_type(str[i], &simple, &complex);
		if (str[i] != '\'' && str[i] != '\"')
			ret[j++] = str[i];
		else if (simple || complex)
		{
			if ((str[i] != '\'' && str[i] != '\"'))
				ret[j++] = str[i];
		}
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*remove_quotes(char *str)
{
	int		simple;
	int		complex;

	simple = 0;
	complex = 0;
	if (!str)
		return (NULL);
	return (loop_ret(simple, complex, str));
}
