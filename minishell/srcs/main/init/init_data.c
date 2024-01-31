/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:05:14 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 15:58:24 by aaespino         ###   ########.fr       */
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
	return (0);
}