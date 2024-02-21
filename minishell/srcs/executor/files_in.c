/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:21:35 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/21 16:28:36 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	files_in(t_info *data, t_list **in_files)
{
	t_list	*head;

	head = *in_files;
	while (head)
	{
		if (access(head->content, F_OK) == 0)
		{
			if (access(head->content, W_OK) != 0)
				return (put_error(data, head->content, ": Permission denied\n",
					 -1), 1);
		}
		else
		{
			return (put_error(data, head->content, ": No such file or directory\n",
				 -1), 1);
		}
		head = head->next;
	}
	return (0);
}
