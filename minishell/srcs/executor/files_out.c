/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:39:50 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/15 13:22:56 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int comprove_stdout(t_info *data)
{
	int		fd;
	t_list	*head;

	head = data->list_out_files;
	while (head)
	{
		fd = open(head->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			dprintf(2, "minishell: ");
			perror (head->content);
			exit (1);
//			return (perror ("open"), 1);
		}
		close(fd);
		head = head->next;
	}
	return (0);
}
