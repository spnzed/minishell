/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:43:28 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/29 20:01:08 by aaespino         ###   ########.fr       */
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
	char	*temp;

	head = env;
	while (head)
	{
		temp = ft_before_set(head->content, '=');
		if (ft_strcmp(temp, var) == 0)
		{
			if (temp)
				free(temp);
			return (0);
		}
		head = head->next;
	}
	if (temp)
		free(temp);
	return (1);
}

t_environment	*get_var_list(t_environment *env, char *var)
{
	t_environment	*head;

	head = env;
	while (head)
	{
		if (ft_strcmp(head->signal, var) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

char	*get_var_init(t_environment *env, char *var)
{
	t_environment	*head;

	head = env;
	while (head)
	{
		if (ft_strcmp(head->signal, var) == 0)
			return (head->content);
		head = head->next;
	}
	return (NULL);
}
