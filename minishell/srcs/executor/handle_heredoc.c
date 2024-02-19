/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:38:51 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/19 20:20:49 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void remove_heredoc_file()
{
	
}

static void	putstr_newl_fd(char *str, int fd)
{
	if (!str || !fd)
		return ;
	ft_putstr_fd (str, fd);
	write (fd, "\n", 1);
}

/*
	REMOVE_HEREDOC_FILE;

	El valor 0644 es un número octal que representa los permisos de acceso del 
	archivo que se va a crear o truncar. En sistemas Unix y Linux, los permisos 
	de acceso de un archivo determinan quién puede leer, escribir y ejecutar ese archivo.

El número 0644 se divide en tres partes:

    El primer dígito (0) indica que el valor está en base octal.
    Los siguientes tres dígitos (644) representan los permisos de acceso del archivo.

Los permisos de acceso se dividen en tres grupos:

    El primer dígito (6) indica los permisos del propietario del archivo.
    Los siguientes dos dígitos (4 y 4) indican los permisos del grupo al 
	que pertenece el archivo.
    Los últimos tres dígitos (4 y 4) indican los permisos para otros usuarios 
	que no son el propietario ni están en el grupo del archivo.

Cada grupo de tres dígitos representa los permisos de lectura, escritura y 
ejecución, respectivamente, para el propietario, el grupo y otros usuarios.

En el caso de 0644:

    El propietario tiene permisos de lectura y escritura (6), representado por 110 en binario.
    El grupo tiene permisos de solo lectura (4), representado por 100 en binario.
    Otros usuarios tienen permisos de solo lectura (4), representado por 100 en binario.

*/
static void	heredoc_loop(t_list *head, int fd)
{
	char *line;

	while (head)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, head->content) == 0)
		{
			close (fd);
			if (head->next)
			{
				remove_heredoc_file();
				fd = open(HEREDOC_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (fd == -1)
					return (perror ("open"));
			}
			head = head->next;
		}
		else
			putstr_newl_fd(line, fd);
		free (line);
	}
	close(fd);
}

void	handle_heredoc(t_info *data)
{
	int		fd;
	t_list	*temp;

	signal(SIGINT, signal_handler_heredoc);
	signal(SIGQUIT, signal_handler_heredoc);
	fd = open(HEREDOC_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (perror ("open"));
	temp = data->list_heredoc;
	heredoc_loop(temp, fd);
}
