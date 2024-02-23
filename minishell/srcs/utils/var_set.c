/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:36:19 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/23 11:10:57 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_var(t_list **head, char *id, char *value) //ARREGLAR MANANA
{
	t_list	*temp;
	char *tmp;

	temp = *head;
	tmp = ft_strjoin(id, "=");
	value = ft_strjoin(id, value);

	if (var_found_list(*head, id))
	{
		if (temp->content)
			free(temp->content);
		temp->content = ft_strdup(value);
	}
	else
		add_variable_list(head, value);
}

void	add_variable_list(t_list **head, char *value)
{
	t_list	*new_node;

	new_node = ft_lstnew(value);
	ft_lstadd_back(head, new_node);
}
// set_var(*list_env, var, path)