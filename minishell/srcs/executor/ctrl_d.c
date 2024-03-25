/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:22:48 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/25 17:31:01 by aaespino         ###   ########.fr       */
/*   Updated: 2024/03/21 16:09:11 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ctrl_d(t_info *data)
{
	if (isatty(STDIN_FILENO))
		write(2, "exit\n", 6);
	exit(data->exit_id);
}
