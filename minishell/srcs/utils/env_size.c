/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:01:17 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/08 19:01:27 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_environmentsize(t_environment *env)
{
	int	size;

	size = 0;
	while (env)
	{
		env = env->next;
		size++;
	}
	return (size);
}
