/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:36:19 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/10 12:44:27 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	found_id(t_list *temp, char *id, char *value, int x)
{
	char	*content;
	char	*id_equals_find;

	content = NULL;
	id_equals_find = NULL;
	id_equals_find = ft_before_set(temp->content, '=');
	if (ft_strcmp(id, id_equals_find) == 0)
	{
		if (x > 1)
			free(temp->content);
		content = ft_strdup(value);
		temp->content = content;
		free(id_equals_find);
		return (1);
	}
	free(id_equals_find);
	return (0);
}

void	set_var(t_list *head, char *id, char *value)
{
	t_list		*temp;
	char		*id_equals;
	static int	x;

	if (!x)
		x = 0;
	temp = head;
	id_equals = ft_strjoin(id, "=");
	value = ft_strjoin(id_equals, value);
	if (var_found_list(head, id) == 0)
	{
		while (temp)
		{
			if (found_id(temp, id, value, x))
				break ;
			temp = temp->next;
		}
	}
	else
		add_variable_list(head, value);
	free(id_equals);
	free(value);
	x++;
}

void	add_variable_list(t_list *head, char *value)
{
	t_list	*new_node;

	new_node = ft_lstnew(value);
	ft_lstadd_back(&head, new_node);
}
