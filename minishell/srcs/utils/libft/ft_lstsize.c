/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:18:23 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/03 15:21:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize (t_list *lst)
{
	size_t size;
	
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return ((int)size);
}