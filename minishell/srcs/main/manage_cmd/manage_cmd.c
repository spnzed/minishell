/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:38:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/07 18:51:59 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parser(t_info *data)
{
	data->cmd_nbr = counter_cmd(data->cmd_line);
	if (syntax_error(data))
		return (0);
	while (search_var(data->cmd_line))
		data->cmd_line = parse_var(data);
	data->mul_cmds = ft_split(data->cmd_line, ' ');
	data->cmd_line = ft_normal(data->cmd_line);
}

static void executor(t_info *data)
{
	if (data->cmd_nbr)
		exec_cmds(data);
	ft_builtins(data);
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

// int	manage_cmd(t_info *data)
// {
// 	data->cmd_nbr = counter_cmd(data->cmd_line);
// 	if (syntax_error(data))
// 		return (0);
// 	while (search_var(data->cmd_line))
// 		data->cmd_line = parse_var(data);
// 	if (data->cmd_nbr)
// 	{
// 		prepare_exec(data);
// 		executor(data);
// 	}
//  	data->split_line = ft_split(data->cmd_line, ' ');
// 	data->cmd_line = ft_normal(data->cmd_line);
// 	ft_builtins(data);
// 	return (0);
// }