/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:05:14 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/03 12:12:40 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer(t_info *data, char **env)
{
	if (init_env(data, env))
		return (ft_putstr_fd("Error initializing environment\n", 2), 1);
	// if (init_settings(data))
	// 	return (ft_putstr_fd("Error initializing terminal settings\n", 2), 1);
	if (init_fd(data))
		return (ft_putstr_fd("Error initializing terminal file descriptors\n",
				2), 1);
	data->exit_id = 0;
	return (0);
}
