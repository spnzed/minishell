/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:38:43 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/23 17:51:05 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*

STDIN: es el flujo de entrada estándar usado para ingresar datos en un programa, 
típicamente asociado al teclado.

STDOUT: es el flujo de salida estándar utilizado para mostrar resultados y mensajes 
de salida de un programa, comúnmente asociado a la pantalla o terminal.

/////////////////////////////////////////////////////////////////////////////////////

(O_WRONLY): Abre el archivo en modo escritura.
(O_RDONLY): Abre el archivo en modo lectura.
(O_CREAT): Crea el archivo si no existe.

finalmente

(O_TRUNC): Trunca el archivo a longitud cero si existe
(O_APPEND): Añade los datos al final del archivo.

/////////////////////////////////////////////////////////////////////////////////////

stdout_to_file_overwrite: redirigir stdout a un archivo, sobrescribiendo su contenido

stdout_to_file_append: redirigir stdout a un archivo, añadiendo al final de su contenido

stdin_from_file: redirigir stdin desde un archivo

/////////////////////////////////////////////////////////////////////////////////////

TLDR

	El primero sobreescribe al el archivo desde el principio de este
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	El segundo añade contenido al archivo al final
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);

	El tercero recibe los inputs desde un archivo, y no desde nuestro teclado
	fd = open(filename, O_RDONLY);

*/
static void handle_file(char *file, int open_code, int std_mode, int num)
{
	int	fd;

	if (num > 0)
		fd = open(file, open_code, num);
	else
		fd = open(file, open_code);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	if (dup2(fd, std_mode) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close (fd);
}

static void launch_handler(t_info *data)
{
	if (data->is_heredoc)
		handle_heredoc(data);
	if (data->file_overwrite)
		handle_file(data->file_overwrite, O_WRONLY | O_CREAT | O_TRUNC, STDOUT_FILENO, 0644);
	if (data->file_append)
		handle_file(data->file_append, O_WRONLY | O_CREAT | O_APPEND, STDOUT_FILENO, 0644);
	if (data->from_file)
		handle_file(data->from_file, O_RDONLY, STDIN_FILENO, 0);
}

int handle_redirect(t_info *data)
{
	if ((data->list_out_files || data->list_out_append) && files_out(data))
		return (1);
	if (data->list_in_files && files_in(data, &data->list_in_files))
		return (1);
	launch_handler(data);
	remove_heredoc();
	return (0);
}
