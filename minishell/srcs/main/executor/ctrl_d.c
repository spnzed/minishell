/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:22:48 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/30 15:13:42 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_d(char *buf, int r, t_info *data)
{
	if (!data->list_input)
	{
		ft_putstr_fd("exit\n", 1);
		exit(free_all(data, 1));
	}
	else
		buf[r] = '\0';
}