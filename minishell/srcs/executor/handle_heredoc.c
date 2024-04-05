/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:38:51 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/05 21:22:02 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	struct stat es una estructura definida en la biblioteca estándar de C 
	(<sys/stat.h>) que contiene información sobre un archivo, como su tipo, 
	tamaño, permisos, etc. En este contexto, se utilizará para almacenar
	 información 
	sobre el archivo que se va a verificar y, potencialmente, eliminar.

	access()	Comprueba si el archivo existe
	stat()		Obtiene información sobre el archivo
	S_ISREG()	Verifica si un archivo es regular
	unlink()	Elimina el archivo si es regular
*/
void	remove_heredoc(void)
{
	struct stat	info;

	if (access(HEREDOC, F_OK) != -1)
	{
		if (stat(HEREDOC, &info) == 0)
		{
			if (S_ISREG(info.st_mode))
				unlink(HEREDOC);
		}
		else
			perror("stat");
	}
}

static void	putstr_newl_fd(char *str, int fd)
{
	if (!str || !fd)
		return ;
	ft_putstr_fd (str, fd);
	write (fd, "\n", 1);
}

/*
	El valor 0644 es un número octal que representa los permisos de acceso 
	del 
	archivo que se va a crear o truncar. En sistemas Unix y Linux, los 
	permisos 
	de acceso de un archivo determinan quién puede leer, escribir y ejecutar 
	ese archivo.

El número 0644 se divide en tres partes:

    El primer dígito (0) indica que el valor está en base octal.
    Los siguientes tres dígitos (644) representan los permisos de acceso del
	 archivo.

Los permisos de acceso se dividen en tres grupos:

    El primer dígito (6) indica los permisos del propietario del archivo.
    Los siguientes dos dígitos (4 y 4) indican los permisos del grupo al 
	que pertenece el archivo.
    Los últimos tres dígitos (4 y 4) indican los permisos para otros usuarios 
	que no son el propietario ni están en el grupo del archivo.

Cada grupo de tres dígitos representa los permisos de lectura, escritura y 
ejecución, respectivamente, para el propietario, el grupo y otros usuarios.

En el caso de 0644:

    El propietario tiene permisos de lectura y escritura (6), representado 
	por 110 en binario.
    El grupo tiene permisos de solo lectura (4), representado por 100 
	en binario.
    Otros usuarios tienen permisos de solo lectura (4), representado por 
	100 en binario.

*/

static int	condition(char *line, t_list **head, int *fd)
{
	if (ft_strcmp(line, (*head)->content) == 0)
	{
		if ((*head)->next)
		{
			close (*fd);
			remove_heredoc();
			*fd = open(HEREDOC, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (*fd == -1)
				return (1);
		}
		*head = (*head)->next;
	}
	else
		putstr_newl_fd(line, *fd);
	return (0);
}

int	comprove_heredoc_mul(t_info *data, char *cmd, int nbr)
{
	int		fd;
	char	*line;
	t_list	*head;

	signal(SIGINT, signal_handler_heredoc);
	signal(SIGQUIT, signal_handler_heredoc);
	fd = open(data->HEREDOC_keys[nbr], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (perror ("open"), 1);
	get_redirections(cmd, data);
	head = data->list_heredocs;
	while (head)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (condition (line, &head, &fd) == 1)
			return (perror ("open"), 1);
		free (line);
	}
	close(fd);
	return (0);
}

int	comprove_heredoc(t_info *data)
{
	int		fd;
	char	*line;
	t_list	*head;

	signal(SIGINT, signal_handler_heredoc);
	signal(SIGQUIT, signal_handler_heredoc);
	fd = open(HEREDOC, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (perror ("open"), 1);
	head = data->list_heredocs;
	while (head)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (condition (line, &head, &fd) == 1)
			return (perror ("open"), 1);
		free (line);
	}
	close(fd);
	return (0);
}