/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:24:42 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/16 16:29:51 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parent_process(t_info *data)
{
	dup2(data->fd[0], STDIN_FILENO);
	close(data->fd[0]);
	close(data->fd[1]);
	return (0);
}
