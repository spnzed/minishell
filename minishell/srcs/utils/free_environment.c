/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:47:13 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/11 17:28:11 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_environment(t_environment *env)
{
	if (env)
	{
		if (env->full_line)
		{
			free(env->full_line);
			env->full_line = NULL;
		}
		if (env->signal)
		{
			free(env->signal);
			env->signal = NULL;
		}
		if (env->content)
		{
			free(env->content);
			env->content = NULL;
		}
		free(env);
	}
}
