/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:22:48 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/09 14:58:59 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ctrl_d(t_info *data)
{
	if (isatty(STDIN_FILENO))
		write(2, "exit\n", 6);
	exit(data->cmd_return); // New add
}
