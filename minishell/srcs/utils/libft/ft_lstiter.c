/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:51:51 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/03 17:57:44 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstiter(t_list *lst, void(*f)(void *))
{
	if (!lst || !f)
		return (0);
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
