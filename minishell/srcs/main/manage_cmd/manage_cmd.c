/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:38:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/06 18:54:56 by aaespino         ###   ########.fr       */
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
	while (search_var(data->cmd_line)) // work aaespino
	{
		data->cmd_line = parse_var(data); // work aaespino
		if (data->cmd_line)
			break ;
	}
 	data->split_line = ft_split(data->cmd_line, ' ');
	data->cmd_line = ft_normal(data->cmd_line);
	ft_builtins(data);
	return (0);
}
