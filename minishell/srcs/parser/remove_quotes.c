/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:40:44 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/26 16:07:00 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	int		simple;
	int		complex;
	char	*ret;

	i = 0;
	j = 0;
	simple = 0;
	complex = 0;
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
	free(str);
	return (ret);
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
