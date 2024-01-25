/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:22:46 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/25 17:24:55 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_c(t_info *data)
{
	data->ret = 130;
	ft_lstclear(&data->list_input, &free_token);
	ft_putstr_fd("\n->", 1);
}