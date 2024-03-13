/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:49:12 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/16 18:51:14 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	reset_fd(t_info *data)
{
	if (dup2(data->std_in, STDIN_FILENO) == -1)
		return (1);
	if (dup2(data->std_out, STDOUT_FILENO) == -1)
		return (1);
	return (0);
}
