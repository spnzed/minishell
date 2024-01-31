/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:05:14 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 18:31:16 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_data(t_info *data, char **env)
{
	if (init_env(data, env))
		return (write(2, "Error initializing environment\n", 32));
	if (init_settings(data))
		return (write(2, "Error initializing terminal settings\n", 38));
	if (init_fd(data))
		return (write(2, "Error initializing terminal file descriptors\n", 46));
	data->status = 0;
	return (0);
}