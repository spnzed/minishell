/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:22:20 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/06 16:20:50 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_struct_tlist(t_list *list)
{
	t_list	*temp;

	temp = list;
	while(list->next)
	{
		printf("%s\n",temp->content);
		temp = temp->next;
	}
}