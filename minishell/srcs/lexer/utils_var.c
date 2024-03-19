/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:43:28 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/12 16:19:39 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*value_export(t_env *signals_env, char *value)
{
	t_env	*head;

	head = signals_env;
	while (head != NULL)
	{
		if (ft_strcmp(head->content, value) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_env	*var_export(t_env *signals_env, char *var)
{
	t_env	*head;

	head = signals_env;
	while (head)
	{
		if (ft_strcmp(head->signal, var) == 0)
			return (head);
		head = head->next;
	}
	return (0);
}

int	var_found_env(t_env *signals_env, char *var)
{
	t_env	*head;

	head = signals_env;
	while (head)
	{
		if (ft_strcmp(head->signal, var) == 0)
			return (1);
		head = head->next;
	}
	return (0);
}

int	var_found_list(t_list *env, char *var)
{
	t_list	*head;
	char	*temp;

	head = env;
	while (head)
	{
		temp = ft_before_set(head->content, '=');
		if (ft_strcmp(temp, var) == 0)
			return (0);
		head = head->next;
	}
	return (1);
}

t_list	*get_var_list(t_list *env, char *var)
{
	t_list	*head;

	head = env;
	while (head)
	{
		if (ft_strcmp(ft_before_set(head->content, '='), var) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}
