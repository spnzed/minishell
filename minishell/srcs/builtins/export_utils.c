/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/03 12:29:50 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_environmentsize(t_environment *env)
{
	int	size;

	size = 0;
	while (env)
	{
		env = env->next;
		size++;
	}
	return (size);
}

t_environment	*loop_exp(int index, int len, t_environment *exp_order)
{
	t_environment	*temp;
	t_environment	*tempvar;

	while (index < len)
	{
		temp = exp_order;
		while (temp->next != NULL)
		{
			if ((ft_strcmp(temp->signal, temp->next->signal)) > 0)
			{
				tempvar = temp->next;
				temp->next = temp->next->next;
				tempvar->next = exp_order;
				exp_order = tempvar;
			}
			else
				temp = temp->next;
		}
		index++;
	}
	return (exp_order);
}

void	sub_var(t_list *list, char *signal, char *content)
{
	int		len;
	char	*new_content;

	len = ft_strlen(signal) + ft_strlen(content) + 2;
	while (list)
	{
		if (ft_strcmp(ft_before_set(list->content, '='), signal) == 0)
		{
			new_content = malloc(sizeof(char) * len);
			new_content = ft_strjoin(signal, "=");
			new_content = ft_strjoin(new_content, content);
			list->content = ft_memcpy(list->content, new_content, len);
		}
		list = list->next;
	}
}

int	search_on_lists(t_info *data, t_environment *list, char *str)
{
	char	*signal;
	char	*content;

	signal = ft_before_set(str, '=');
	content = ft_after_set(str, '=');
	while (list)
	{
		if (ft_strcmp(signal, list->signal) == 0)
		{
			list->content = ft_strdup(content);
			list->full_line = ft_strjoin(signal, "=");
			list->full_line = ft_strjoin(list->full_line, content);
			if (!var_found_list(data->list_env, signal))
				sub_var(data->list_env, signal, content);
			else
				return (1);
			free (signal);
			free (content);
			return (0);
		}
		list = list->next;
	}
	free (signal);
	free (content);
	return (1);
}

int	search_list_else(t_environment *list, char *signal)
{
	while (list)
	{
		if (ft_strcmp(signal, list->signal) == 0)
			return (0);
		list = list->next;
	}
	return (1);
}
