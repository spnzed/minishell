/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:33 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/26 16:22:21 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Obtiene la configuración actual del terminal de entrada y la almacena en data->n_settings
		En caso de error, imprime un mensaje de error específico y devuelve 1
	Copia la configuración actual del terminal en data->o_settings para conservarla
	Modifica la configuración para desactivar la impresión de caracteres de control
	Establece la nueva configuración del terminal de entrada
		En caso de error, imprime un mensaje de error específico y devuelve 1
	Si todas las operaciones se realizan con éxito, devuelve 0

	MACROS

		STDIN_FILENO: Descriptor de archivo para la entrada estándar
		ECHOCTL: Macro para desactivar la impresión de caracteres de control
		TCSANOW: Constante para aplicar cambios en la configuración del terminal inmediatamente
*/
int	init_settings(t_info *data)
{
	if (tcgetattr(STDIN_FILENO, &data->n_settings) != 0)
	{
		perror("tcgetattr");
		return (1);
	}
	data->o_settings = data->n_settings;
	data->n_settings.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &data->n_settings) != 0)
	{
		perror("tcsetattr");
		return (1);
	}
	return (0);
}
