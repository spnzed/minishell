/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_var2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:43:28 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/01 14:07:51 by pquintan         ###   ########.fr       */
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
