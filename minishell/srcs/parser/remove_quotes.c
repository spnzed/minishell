/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:40:44 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/28 17:53:51 by pquintan         ###   ########.fr       */
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

// static char **clean_splitted_quotes(char **spl)
// {
// 	int		i;
// 	int		size;
// 	char	**ret_spl;

// 	i = -1;
// 	size = ft_arrlen(spl);
// 	ret_spl = malloc(sizeof(char *) * size + 1);
// 	while (spl[++i])
// 		ret_spl[i] = ft_strdup(remove_quotes(spl[i]));
// 	ret_spl[i] = NULL;
// 	free(spl);
// 	return (ret_spl);
// }
