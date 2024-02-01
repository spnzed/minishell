/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:38:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/01 18:49:15 by pquintan         ###   ########.fr       */
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
	// cmd
	data->split_line = ft_split(data->cmd_line, ' ');
	ft_builtins(data);
	return (0);
}
