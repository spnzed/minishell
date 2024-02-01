/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:42:01 by pquintan          #+#    #+#             */
/*   Updated: 2024/01/31 17:57:51 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" // New add

char	**free_array(char **Array, int len)
{
	while (len > 0)
		free(Array[--len]);
	free(Array);
	return (NULL);
}

int		array_size(char **Array)
{
	int len;
	char **temp;

	len = 0;
	temp = Array;
	while (temp)
	{
		temp++;
		len++;
	}
	return(len);
}