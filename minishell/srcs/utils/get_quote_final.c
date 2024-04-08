/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:26:52 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 12:29:57 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_quote_final(char *line, int i, int *simple, int *complex)
{
	i++;
	while (ft_isprint(line[i]))
	{
		get_quotes_type(line[i], simple, complex);
		if (*simple == 0 && *complex == 0)
			break ;
		i++;
	}
	while (line[i] && line[i] != ' ')
		i++;
	return (i);
}
