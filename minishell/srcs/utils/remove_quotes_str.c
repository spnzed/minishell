/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:26:44 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/22 12:19:34 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_remove_quotes_str(char *str)
{
	int		i;
	int		x;
	char	*copy;
	
	i = 0;
	x = 0;
	if (!str)
		return (NULL);
	copy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while(str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			i++;
		else
		{
			copy[x] = str[i];
			x++;
			i++;
		}
	}
	copy[x] = '\0';
	return(copy);
}
