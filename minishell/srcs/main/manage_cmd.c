/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:38:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/09 14:51:26 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parser(t_info *data)
{
	data->cmd_nbr = cmd_count(data->cmd_line);
	if (syntax_error(data))
		return ;
	while (search_var(data->cmd_line))
		data->cmd_line = parse_var(data);
	data->cmd_line = normalizer(data->cmd_line);
	data->split_line = ft_split(data->cmd_line, ' ');
	ft_builtins(data);
}

static void executor(t_info *data)
{
	if (data->cmd_nbr)
		exec_cmds(data);
}

/*manage_cmd

	✅1. Cuenta cantidad de comandos	
	✅2. Comprueba la syntax		
	✅3. Busca variables de entorno, y las parsea
	4. Comprueba que no sea todo espacio
	5. 	Inicia->Ejecuta->Libera (Para uno o mas argumentos)
*/
int	manage_cmd(t_info *data)
{
	parser(data);
	executor(data);
	return (0);
}
