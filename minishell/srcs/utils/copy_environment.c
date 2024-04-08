/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:58:56 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/08 12:29:33 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_environment(t_environment *head)
{
	t_environment	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

t_environment	*ft_copy_environment(const t_environment *src)
{
	t_environment	*head;
	t_environment	*current_dest;

	head = malloc(sizeof(t_environment));
	current_dest = head;
	if (!src || !head)
		return (NULL);
	while (src)
	{
		current_dest->full_line = src->full_line;
		current_dest->content = src->content;
		current_dest->signal = src->signal;
		src = src->next;
		if (src)
		{
			current_dest->next = malloc(sizeof(t_environment));
			if (!current_dest->next)
				return (ft_free_environment(head), NULL);
			current_dest = current_dest->next;
		}
		else
			current_dest->next = (NULL);
	}
	return (head);
}
