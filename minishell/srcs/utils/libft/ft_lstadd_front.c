/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:10:27 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/03 15:17:59 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list *aux;

	if (!*lst)
		*lst = new;
	else
	{
		aux = new;
		aux->next = *lst;
		*lst = aux;
	}
}