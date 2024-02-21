/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:56:08 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/21 17:00:00 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_info *data)
{
	printf("exit\n");
	exit(data->exit_id);
	return(0);
} // faltan muchas cosas de momento sale y ya
// AYUDA HAY ESTA EXCEPCION
// bash-3.2$ EXIT
// bash: EXIT: command not found