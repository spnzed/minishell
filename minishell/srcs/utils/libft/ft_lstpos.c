/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:28:12 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/23 19:26:51 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstpos(t_list *lst, int *value)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = lst->content;
	while (lst)
	{
		if (*tmp == *value)
			return (i);
		lst = lst->next;
		tmp = lst->content;
		i++;
	}
	return (i);
}
