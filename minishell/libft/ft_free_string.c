/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:19:26 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/11 17:12:27 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_string(void *ptr)
{
	char	*str;

	if (ptr)
	{
		ft_bzero(ptr, ft_strlen(ptr));
		str = (char *)ptr;
		free(str);
		str = 0;
	}
}
