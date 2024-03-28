/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:38:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/28 14:18:03 by pquintan         ###   ########.fr       */
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
static int  little_cases(t_info *data, char *line)
{
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

static void one_command (t_info *data)
{
    if (little_cases(data, data->cmd_line))
        return ;
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
}

static void expander(t_info *data)
{
	if (ft_strchr(data->cmd_line, '$'))
	{
		while (comprove_var(data->cmd_line))
			data->cmd_line = parse_var(data);
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
