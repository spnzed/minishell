/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   manage_cmd.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pquintan <pquintan@student.42barcelona.	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/31 17:38:55 by aaespino		  #+#	#+#			 */
/*   Updated: 2024/03/28 14:43:43 by pquintan		 ###   ########.fr	   */
/*																			*/
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

static int	little_cases(t_info *data, char *line)
{
	if (line[0] == ' ')
	{
		while (*line == ' ')
			line++;
	}
	if (ft_strcmp(line, "\" \"") == 0)
	{
		ft_putstr_fd(
			"minishell: line 1: : command not found\n", 2);
		data->exit_id = 127;
		return (1);
	}
	if (ft_strcmp(line, "\"\"") == 0)
	{
		ft_putstr_fd(
			"minishell: line 1: : command not found\n", 2);
		data->exit_id = 127;
		return (1);
	}
	return (0);
}

// static void	one_command(t_info *data)  // PARA QUITAR FUNCIONES
// {
// 	if (little_cases(data, data->cmd_line))
// 		return ;
// 	prepare_to_exec_one(data);
// 	exec_one_cmd(data);
// }

// static void	multiple_commands(t_info *data)  // PARA QUITAR FUNCIONES
// {
// 	prepare_to_exec(data);
// 	exec_cmds(data);
// }

// static void	parser(t_info *data) // PARA QUITAR FUNCIONES
// {
// 	syntax_error(data);
// }

static void	expander(t_info *data)
{
	if (ft_strchr(data->cmd_line, '$'))
	{
		while (comprove_var(data->cmd_line))
			data->cmd_line = parse_var(data);
	}
}

static void	executor(t_info *data)
{
	if (data->cmd_line)
	{
		if (data->cmd_nbr == 1)
		{
			if (little_cases(data, data->cmd_line))
				return ;
			prepare_to_exec_one(data);
			exec_one_cmd(data);
		}
		else if (data->cmd_nbr > 1)
		{
			if (!prepare_to_exec(data))
				exec_cmds(data);
		}
	}
}

int	manage_cmd(t_info *data)
{
	syntax_error(data);
	expander(data);
	executor(data);
	return (0);
}
