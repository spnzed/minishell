/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:38:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 18:44:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*manage_cmd

	1. Cuenta cantidad de comandos
	2. Comprueba la syntax
	3. Busca variables, y las parsea
	4. Comprueba que no sea todo espacio
	5. 	Inicia->Ejecuta->Libera (Para uno o mas argumentos)
*/
int	manage_cmd(t_info *data)
{
	data->cmd_nbr = counter_cmd(data->cmd_line);
	if (syntax_error(data))
		return (0);
	return (0);
}
