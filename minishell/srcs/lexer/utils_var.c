/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:43:28 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/10 13:41:39 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	var_found_env(t_environment *signals_env, char *var)
{
	t_environment	*head;

	head = ft_copy_environment(signals_env);
	while (head)
	{
		if (ft_strcmp(head->signal, var) == 0)
			return (1);
		head = head->next;
	}
	free_environment(head);
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
			free(temp);
			return (0);
		}
		if (temp)
			free(temp);
		head = head->next;
	}
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
