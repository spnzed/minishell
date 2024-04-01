/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:39:50 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/01 19:31:30 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	comprove_stdout(t_info *data)
{
	int		fd;
	t_list	*head;

	head = data->list_out_files;
	while (head)
	{
		fd = open(head->content, O_WRONLY | O_CREAT, 0644);
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
