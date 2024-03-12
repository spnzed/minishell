/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:08:10 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 15:59:06 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Obtiene el descriptor de archivo actual para la entrada estándar
	Obtiene el descriptor de archivo actual para la salida estándar
	Retorna 0 si todas las operaciones se realizan con éxito

	MACROS

		STDIN_FILENO: Descriptor de archivo para la entrada estándar.
		STDIN_FILENO: Descriptor de archivo para la salida estándar.

	dup: Duplica un descriptor de archivo existente.
    perror: Imprime un mensaje de error describiendo el último error encontrado.

*/
int	init_fd(t_info *data)
{
	data->std_in = dup(STDIN_FILENO);
	data->std_out = dup(STDOUT_FILENO);
	if (data->std_in == -1 || data->std_out == -1)
	{
		perror("dup");
		return (1);
	}
	return (0);
}
