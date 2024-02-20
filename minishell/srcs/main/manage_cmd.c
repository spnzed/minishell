/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:38:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/20 16:36:54 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	manage_cmd

	Proceso:
		parser: 	cuenta la cantidad de comandos teniendo en cuenta las |
					revisa los errores sintacticos
		expander: 	reemplaza las variables que se identifican con $
					"$USER" se convierte entonces en "pquintan"
		executor:	

	TODO:
	✅1. Cuenta cantidad de comandos	
	✅2. Comprueba la syntax		
	✅3. Busca variables de entorno, y las parsea

*/

static void	parser(t_info *data)
{
	data->cmd_nbr = cmd_count(data->cmd_line);
	if (syntax_error(data))
		exit (1);
}

static void expander(t_info *data)
{
	while (search_var(data->cmd_line))
		data->cmd_line = parse_var(data);
}

static void executor(t_info *data)
{
	data->split_line = split_cmds(data); // arreglar espacio
	data->cmd_line = normalizer(data->split_line[0]);
	data->cmd_split = ft_split(data->cmd_line, ' ');
	data->is_builtin = ft_builtins(data);
	// if (data->cmd_nbr)
	// 	exec_cmds(data);
}

int	manage_cmd(t_info *data)
{
	parser(data);
	expander(data);
	executor(data);
	return (0);
}
