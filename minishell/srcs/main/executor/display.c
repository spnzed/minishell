/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:02:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/01 16:01:27 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*display_term_message(void)
{
	char	*line;

	line = readline("42-Minishell ~ % ");
	if (line == NULL)
	{
		free(line);
		return(NULL);
	}
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
