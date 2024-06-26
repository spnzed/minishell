/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:36:19 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/01 18:07:23 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_var(t_list *head, char *id, char *value)
{
	t_list	*temp;
	char	*tmp;

	temp = head;
	tmp = ft_strjoin(id, "=");
	value = ft_strjoin(tmp, value);
	if (var_found_list(head, id) == 0)
	{
		while (temp)
		{
			if (ft_strcmp(id, ft_before_set(temp->content, '=')) == 0)
			{
				temp->content = ft_strdup(value);
				break ;
			}
			temp = temp->next;
		}
	}
	else
		add_variable_list(head, value);
	free(tmp);
	//free(value);
}

void	add_variable_list(t_list *head, char *value)
{
	t_list	*new_node;

	new_node = ft_lstnew(value);
	ft_lstadd_back(&head, new_node);
}
