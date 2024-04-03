/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:43:28 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/03 11:23:20 by pquintan         ###   ########.fr       */
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
