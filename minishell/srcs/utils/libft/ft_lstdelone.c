/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:28:57 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/03 15:48:19 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone (t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del)
		{
			del(lst->content);
			free(lst);
		}
	}
}