/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:21:35 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/19 19:33:14 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	files_in(t_list **in_files)
{
	t_list	*head;

	head = *in_files;
	while (head)
	{
		if (access(head->content, F_OK) == 0)
			if (access(head->content, W_OK) != 0)
				return (put_error(head->content, ": Permission denied\n",
					 -1), 1);
		else
			return (put_error(head->content, ": No such file or directory\n",
				 -1), 1);
		head = head->next;
	}
	return (0);
}
