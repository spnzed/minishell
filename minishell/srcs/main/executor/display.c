/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:02:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/01 17:26:44 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*display_term_message(void)
{
	char	*line;

	line = readline(BLUE"42-MiniCONCHIS ~ % "RESET);
	if (line == NULL || *line == '\0')
		return(free(line), NULL);
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
