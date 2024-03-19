/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:23:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/15 13:53:28 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_error(t_info *data, char *cmd, char *str, int ret)
{
	ft_putstr_fd("minishell: ", 2);
	if (cmd)
		ft_putstr_fd(cmd, 2);
	ft_putstr_fd(str, 2);
	if (ret < 0)
		return ;
	data->exit_id = ret;
	exit (ret);
}

void put_error_prev(t_info *data, char *cmd, char *str, int ret)
{
	ft_putstr_fd("minishell: ", 2);
	if (cmd)
		ft_putstr_fd(cmd, 2);
	ft_putstr_fd(str, 2);
	if (ret < 0)
		return ;
	data->exit_id = ret;
}
