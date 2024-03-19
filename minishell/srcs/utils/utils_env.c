/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:59:16 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/12 16:19:39 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_envdelone(t_env *env, void (*del)(void *))
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

t_env	*ft_envnew(void *content)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (0);
	new_node->full_line = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_envclear(t_env **env, void (*del)(void*))
{
	t_env	*aux;

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

void	ft_envadd_back(t_env **env, t_env *new)
{
	t_env	*aux;

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
