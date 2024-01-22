/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:58:00 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/03 18:05:31 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *aux_lst;
	int count = 0;

	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	aux_lst = (t_list *)malloc(count * sizeof(t_list));
	while (lst)
	{
		aux_lst = f(lst->content);
		lst = lst->next;
	}
	return (aux_lst);
}