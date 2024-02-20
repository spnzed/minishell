/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/20 16:22:00 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void delete_node_exp(t_environment **list, char *str)
{
	t_environment *current;
	t_environment *previous;

	current = *list;
	previous = NULL;

	while (current != NULL)
	{
		if (ft_strcmp(str, current->signal) == 0)
		{
			if (previous == NULL)
				*list = current->next;
			else
				previous->next = current->next;
			free(current);
			return;
		}
		previous = current;
		current = current->next;
	}
}


static void delete_node_env(t_list **list, char *str)
{
	char *temp;
	t_list *current;
	t_list *previous;

	current = *list;
	previous = NULL;

	while (current != NULL)
	{
		temp = ft_before_set(current->content, '=');
		if (ft_strcmp(str, temp) == 0)
		{
			if (previous == NULL)
				*list = current->next;
			else
				previous->next = current->next;
			free(temp);
			free(current->content);
			free(current);
			return;
		}
		previous = current;
		current = current->next;
	}
	free(temp);
}

int	ft_unset(t_info *data)
{
	data->str_trim = ft_strtrim(data->cmd_line, "unset ");
	delete_node_env(&data->list_env, data->str_trim);
	delete_node_exp(&data->list_exp, data->str_trim);
	return(7);
}

// solo puede dar un error que es de sintaxis
// sera una funcion que servira tanto para el export como para el unset
// EJEMPLOS:
// bash-3.2$ unset 1fsg
// bash: unset: `1fsg': not a valid identifier
// bash-3.2$ export 764fskalldgg
// bash: export: `764fskalldgg': not a valid identifier
