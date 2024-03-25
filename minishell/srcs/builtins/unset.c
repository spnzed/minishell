/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/21 15:56:14 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	delete_node_exp(t_environment **list, char *str)
{
	t_environment	*current;
	t_environment	*previous;

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
			return ;
		}
		previous = current;
		current = current->next;
	}
}

static void	delete_node_env(t_list **list, char *str)
{
	char	*temp;
	t_list	*current;
	t_list	*previous;

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
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
	free (temp);
}

static void	unset_error_not_valid_id(char *arg, t_info *data)
{
	ft_putstr_fd("minishell: unset: `", 2);
	ft_putstr_fd(ft_remove_quotes_str(arg), 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	data->exit_id = 1;
}

static int	unset_valid(t_info *data)
{
	char	*non_alnum;
	char	*alnum;
	char	*found;
	char	*var;

	var = ft_after_set(data->cmd_line, ' ');
	var = ft_before_set(var, '=');
	non_alnum = ft_strdup(" !#$%%&\\()*+,-./:;<>@[]^`{|}~");
	alnum = ft_strdup("1234567890");
	found = ft_strpbrk(var, non_alnum);
	found = ft_strjoin(found, ft_strpbrk(var, alnum));
	if (ft_strlen(found) > 0)
		return (0);
	return (1);
}

int	ft_unset(t_info *data, char **split_cmd)
{
	if (!unset_valid(data))
	{
		unset_error_not_valid_id(split_cmd[1], data);
		return (1);
	}
	delete_node_env(&data->list_env, split_cmd[1]);
	delete_node_exp(&data->list_exp, split_cmd[1]);
	delete_node_exp(&data->signals_env, split_cmd[1]);
	return (0);
}

// solo puede dar un error que es de sintaxis
// sera una funcion que servira tanto para el export como para el unset
// EJEMPLOS:
// bash-3.2$ unset 1fsg
// bash: unset: `1fsg': not a valid identifier
// bash-3.2$ export 764fskalldgg
// bash: export: `764fskalldgg': not a valid identifier
