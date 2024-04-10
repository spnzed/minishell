/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_term_message.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:02:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/10 12:10:18 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*display_term_message(t_info *data)
{
	char	*line;

	line = readline("42-Minishell ~ % ");
	if (!line)
	{
		free_environment(data->signals_env);
		free_environment(data->list_exp);
		if (isatty(STDIN_FILENO))
			write(2, "exit\n", 6);
		free_array(data->env);
		exit (data->exit_id);
	}
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
