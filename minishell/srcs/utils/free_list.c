/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:26:11 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 17:27:18 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list(t_list *list)
{
	t_list	*temp;

	while (list != NULL)
	{
		temp = list->next;
		if (list->content != NULL)
		{
			free(list->content);
			list->content = NULL;
		}
		free(list);
		list = temp;
	}
}
