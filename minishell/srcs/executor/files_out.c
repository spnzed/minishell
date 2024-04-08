/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:39:50 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 17:19:30 by aaespino         ###   ########.fr       */
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
			ft_putstr_fd("minishell: ", 2);
			perror (head->content);
			exit (1);
		}
		close(fd);
		head = head->next;
	}
	return (0);
}
