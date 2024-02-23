/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:43:28 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/23 10:55:52 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_environment	*value_export(t_environment *signals_env, char *value)
{
	t_environment	*head;

	head = signals_env;
	while (head != NULL)
	{
		if (ft_strcmp(head->content, value) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_environment	*var_export(t_environment *signals_env, char *var)
{
	t_environment	*head;

	head = signals_env;
	while (head)
	{
		if (ft_strcmp(head->signal, var) == 0)
			return (head);
		head = head->next;
	}
	return (0);
}

int	var_found_env(t_environment *signals_env, char *var)
{
	t_environment	*head;

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

	head = env;
	while (head)
	{
		if (ft_strcmp(ft_before_set(head->content, '='), var) == 0)
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