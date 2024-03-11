/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:39:50 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/11 18:35:13 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_outfiles(t_list *outfiles)
{
	int		fd;
	t_list	*tmp;

	tmp = outfiles;
	while (tmp)
	{
		fd = open(tmp->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			return (perror ("open"), 1);
		close(fd);
		tmp = tmp->next;
	}
	return (0);
}

static int	open_append(t_list *append)
{
	int		fd;
	t_list	*tmp;

	tmp = append;
	while (tmp)
	{
		fd = open(tmp->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			return (perror ("open"), 1);
		close(fd);
		tmp = tmp->next;
	}
	return (0);
}

int	comprove_stdout(t_info *data)
{
	t_list	*out_files;
	t_list	*append;

	out_files = data->list_out_files;
	append = data->list_out_append;
	if (open_outfiles(out_files) || open_append(append))
		return (1);
	return (0);
}
