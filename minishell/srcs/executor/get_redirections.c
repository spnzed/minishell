/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:38:05 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/15 18:54:55 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_values_loop(char *cmd, int i, t_info *data, int *simple,
		 int *complex)
{
	while (cmd[++i])
	{
		get_quotes_type(cmd[i], simple, complex);
		//	elimina la opcion de >>> y <<<
		if (cmd[i] == '<' && cmd[i + 1] == '<' && cmd[i + 2] == '<'
			&& !*complex && !*simple)
			return ;
		if (cmd[i] == '>' && cmd[i + 1] == '>' && cmd[i + 2] == '>'
			&& !*complex && !*simple)
			return ;
		//	if "<" y no estamos en comillas. Proporcionar entrada desde un archivo al programa
		if (cmd[i] == '<' && cmd[i + 1] != '<'
			&& !*complex && !*simple)
		{
			i++;
			get_value_infile(data, &cmd[i], SIMPLE_INFILE);
		}
		//	if "<<" y no estamos en comillas. Proporcionar entrada (multilineal) desde un archivo al programa
		else if (cmd[i] == '<' && cmd[i + 1] == '<'
			&& !*complex && !*simple)
		{
			i++;
			get_value_infile(data, &cmd[i], HEREDOC_INFILE);
		}
		//	if ">" y no estamos en comillas. Redirigir salida estandar de un programa a un archivo
		else if (cmd[i] == '>' && cmd[i + 1] != '>'
			&& !*complex && !*simple)
		{
			i++;
			get_value_outfile(data, &cmd[i], SIMPLE_OUTFILE);
		}
		//	if ">>" y no estamos en comillas. En lugar de de sobreescribir el contenido del archivo, agrega salida al final del archivo
		else if (cmd[i] == '>' && cmd[i + 1] == '>'
			&& !*complex && !*simple)
		{
			i++;
			get_value_outfile(data, &cmd[i], APPEND_OUTFILE);
		}
	}
}

void	 get_redirections(char *cmd, t_info *data)
{
	int		simple;
	int		complex;

	simple = 0;
	complex = 0;
	get_values_loop(cmd, -1, data, &simple, &complex);
}