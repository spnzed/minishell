/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:26:09 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/11 14:46:12 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	aux = *lst;
	if (*lst)
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	else
	{
		*lst = new;
		((t_list *)lst)->next = NULL;
	}
}
