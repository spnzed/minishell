/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:39:50 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/12 16:54:34 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_outfiles(t_info *data, t_list *outfiles)
{
	int		fd;
	int		size;
	t_list	*tmp;

	tmp = outfiles;
	size = ft_lstsize(outfiles) + 1;
	while (tmp && size--)
		tmp = tmp->next;
	while (tmp)
	{
		if (data->is_append)
			fd = open(tmp->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(tmp->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			dprintf(2, "minishell: ");
			perror (tmp->content);
			exit (1);
//			return (perror ("open"), 1);
		}
		close(fd);
		tmp = tmp->next;
	}
	return (0);
}

int comprove_stdout(t_info *data)
{
	t_list	*outfiles;

	outfiles = data->list_out_files;
	if (open_outfiles(data, outfiles))
		return (1);
	return (0);
}
