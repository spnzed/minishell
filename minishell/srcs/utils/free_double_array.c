/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:05:30 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/30 14:45:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_double_array(void *ptr)
{
	int		i;
	char	**array;

	i = 0;
	array = (char **)ptr;
	while (array[i])
	{
		ft_bzero(array[i], ft_strlen(array[i]));
		free(array[i]);
		array[i] = 0;
		i++;
	}
	free (array);
	array = 0;
}