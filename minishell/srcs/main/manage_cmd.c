/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:38:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/20 11:57:16 by aaespino         ###   ########.fr       */
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
static void	one_command (t_info *data)
{
	prepare_to_exec_one(data);
	exec_one_cmd(data);
}

static void	multiple_commands (t_info *data)
{
	prepare_to_exec(data); //prepare_to_exec_mul(data);
	exec_cmds(data); //exec_mul_cmd(data);
}

static void	parser(t_info *data)
{
	syntax_error(data);
	// if (syntax_error(data))
	//		return ;
}

static void expander(t_info *data)
{
	if (data->cmd_line)
	{
		while (search_var(data->cmd_line))
			data->cmd_line = parse_var(data);
		if (ft_strcmp(data->cmd_line, "echo ñ") == 0)
			printf("ñ");
	}
}

static void executor(t_info *data)
{
	if (data->cmd_line)
	{
		if (data->cmd_nbr == 1)
			one_command(data);
		else if (data->cmd_nbr > 1)
			multiple_commands(data);
	}
}

int	manage_cmd(t_info *data)
{
	parser(data);
	expander(data);
	executor(data);
	return (0);
}
