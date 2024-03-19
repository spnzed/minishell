/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:58:56 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/22 18:41:57 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_env(t_env *head)
{
	t_env	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

t_env	*ft_copy_env(const t_env *src)
{
	t_env	*head;
	t_env	*current_dest;

	head = malloc(sizeof(t_env));
	current_dest = head;
	if (!src)
		return (NULL);
	if (!head)
		return (NULL);
	while (src)
	{
		current_dest->full_line = src->full_line;
		current_dest->content = src->content;
		current_dest->signal = src->signal;
		src = src->next;
		if (src)
		{
			current_dest->next = malloc(sizeof(t_env));
			if (!current_dest->next)
			{
				ft_free_env(head);
				return (NULL);
			}
			current_dest = current_dest->next;
		}
		else
		{
			current_dest->next = (NULL);
		}
	}
	return (head);
}

/*
typedef struct		s_env
{
	char					*full_line;
	char					*signal;
	char					*content;
	struct s_env	*next;
}					t_env;
*/