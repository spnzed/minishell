/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_term_message.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:02:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/20 17:22:08 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*display_term_message(void)
// {
// 	char	*line;

// 	line = readline("42-Minishell ~ % ");
// 	if (line == NULL)
// 		return(free(line), NULL);
// 	if (ft_strlen(line) > 0)
// 		add_history(line);
// 	return (line);
// }

char	*display_term_message(t_info *data)
{
	char	*line;

	line = readline("42-Minishell ~ % ");
	data->exit_id = 0;
	if (!line)
	{
		if (isatty(STDIN_FILENO))
		write(2, "exit\n", 6);
		exit (data->exit_id);
	}
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
