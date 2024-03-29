/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:38:43 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/29 19:56:55 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*

STDIN: es el flujo de entrada estándar usado para ingresar datos en un
 programa, 
típicamente asociado al teclado.

STDOUT: es el flujo de salida estándar utilizado para mostrar resultados 
y mensajes 
de salida de un programa, comúnmente asociado a la pantalla o terminal.

////////////////////////////////////////////////////////////////////////////

(O_WRONLY): Abre el archivo en modo escritura.
(O_RDONLY): Abre el archivo en modo lectura.
(O_CREAT): Crea el archivo si no existe.

finalmente

(O_TRUNC): Trunca el archivo a longitud cero si existe
(O_APPEND): Añade los datos al final del archivo.

///////////////////////////////////////////////////////////////////////////

stdout_to_out_file: redirigir stdout a un archivo, sobrescribiendo su contenido

stdout_to_name_append: redirigir stdout a un archivo, añadiendo al final
 de su contenido

stdin_from_file: redirigir stdin desde un archivo

/////////////////////////////////////////////////////////////////////////////

TLDR

	El primero sobreescribe al el archivo desde el principio de este
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	El segundo añade contenido al archivo al final
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);

	El tercero recibe los inputs desde un archivo, y no desde nuestro teclado
	fd = open(filename, O_RDONLY);

*/
static void	handle_file(t_info *data, char *file, int open_code,
	int std_mode, int num)
{
	int	fd;

	if (num > 0)
		fd = open(file, open_code, num);
	else
		fd = open(file, open_code);
	if (fd == -1)
	{
		dprintf (2, "minishell: ");
		dprintf (2, "line 1: ");
		perror (file);
		exit(1);
	}
	if (dup2(fd, std_mode) == -1 && !data->is_append)
	{
		perror("dup2");
		close (fd);
		exit(1);
	}
}

static void	build_files(t_info *data)
{
	if (ft_strlen(data->string_infile) > 0)
	{
		if (!data->is_heredoc)
			handle_file(data, data->string_infile, O_RDONLY, STDIN_FILENO, 0);
		else
			handle_file(data, HEREDOC, O_RDONLY, STDIN_FILENO, 0);
	}
	if (ft_strlen(data->string_outfile) > 0)
	{
		if (data->is_append)
			handle_file(data, data->string_outfile,
				O_WRONLY | O_CREAT | O_APPEND, STDOUT_FILENO, 0644);
		else
			handle_file(data, data->string_outfile,
				O_WRONLY | O_CREAT | O_TRUNC, STDOUT_FILENO, 0644);
	}
}

int	handle_redirect(t_info *data)
{
	if (comprove_heredoc(data))
		return (1);
	if (comprove_stdout(data))
		return (1);
	if (comprove_stdin(data))
		return (1);
	build_files(data);
	remove_heredoc();
	return (0);
}
