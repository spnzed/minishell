/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quotes_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:09:31 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/09 16:19:50 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**clean_quotes_array(char **array)
{
	int		x;
	char	**res;

	x = 0;
	res = malloc(sizeof(char *) * (ft_arrlen(array) + 1));
	if (!res)
		return (NULL);
	while (array[x])
	{
		res[x] = remove_quotes(array[x]);
		x++;
	}
	res[x] = NULL;
	return (res);
}