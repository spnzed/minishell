/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:39:50 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/19 19:16:32 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_outfiles(t_list *outfiles)
{
	int	fd;

	while (outfiles)
	{
		fd = open(outfiles->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			return (perror ("open"), 1);
		close(fd);
		outfiles = outfiles->next;
	}
	return (0);
}

static int	open_append(t_list *append)
{
	int	fd;

	while (append)
	{
		fd = open(append->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			return (perror ("open"), 1);
		close(fd);
		append = append->next;
	}
	return (0);
}

int files_out(t_info *data)
{
	t_list	*out_files;
	t_list	*append;

	out_files = data->out_files;
	append = data->out_append;
	if (open_outfiles(out_files) || open_append(append))
		return (1);
	return (0);
}
