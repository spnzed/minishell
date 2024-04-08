/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:39:50 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 15:24:53 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	comprove_stdout(t_info *data)
{
	int		fd;
	t_redir_list	*head;

	head = data->list_out_files;
	while (head)
	{
		if (data->list_out_files->type == APPEND_OUTFILE)
			fd = open(head->content, O_WRONLY | O_CREAT, 0644);
		else
			fd = open(head->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			dprintf(2, "minishell: ");
			perror (head->content);
			exit (1);
		}
		close(fd);
		head = head->next;
	}
	return (0);
}
