/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:59:16 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/22 18:41:57 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_envdelone(t_environment *env, void (*del)(void *))
{
	if (env)
	{
		if (del)
		{
			del(env->content);
			free(env);
		}
	}
}

t_environment	*ft_envnew(void *content)
{
	t_environment	*new_node;

	new_node = malloc(sizeof(t_environment));
	if (!new_node)
		return (0);
	new_node->full_line = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_envclear(t_environment **env, void (*del)(void*))
{
	t_environment	*aux;

	if (!*env)
		return ;
	while (*env)
	{
		aux = (*env)->next;
		ft_envdelone(*env, del);
		*env = aux;
	}
	*env = 0;
}

void	ft_envadd_back(t_environment **env, t_environment *new)
{
	t_environment	*aux;

	aux = *env;
	if (*env)
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	else
		*env = aux;
}
