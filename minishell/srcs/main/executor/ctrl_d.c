/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:22:48 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/02 16:23:11 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ctrl_d(t_info *data)
{
	if (isatty(STDIN_FILENO))
		write(2, "exit\n", 6);
	//free_env(data->list_env); // New add
	//free_array(data->env, array_size(data->env)); // New add
	exit(data->cmd_return); // New add
}
