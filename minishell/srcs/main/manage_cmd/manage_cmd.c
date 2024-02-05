/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:38:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/05 16:21:36 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*manage_cmd

	✅1. Cuenta cantidad de comandos	
	✅2. Comprueba la syntax		
	3. Busca variables de entorno, y las parsea
	4. Comprueba que no sea todo espacio
	5. 	Inicia->Ejecuta->Libera (Para uno o mas argumentos)
*/
int	manage_cmd(t_info *data)
{
	data->cmd_nbr = counter_cmd(data->cmd_line);
	if (syntax_error(data))
		return (0);
	//while (search_var(data->cmd_line)) // work aaespino
	//	data->cmd_line = parse_var(data); // work aaespino
 	data->split_line = ft_split(data->cmd_line, ' '); // work pquintan
	ft_builtins(data); // work pquintan
	return (0);
}
