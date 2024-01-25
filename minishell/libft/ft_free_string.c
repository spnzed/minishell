/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:19:26 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/23 16:25:50 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_string(void *ptr)
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
