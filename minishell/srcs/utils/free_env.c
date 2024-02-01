/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:46:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/01/31 17:53:04 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_list *env)
{
	t_list *temp;

	temp = env;
	while(temp != NULL)
	{
		if (temp->content)
			free(temp->content);
		temp = env->next;
	}
}
