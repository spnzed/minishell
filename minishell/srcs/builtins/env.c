/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/08 16:59:12 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_builtin(t_info *data, t_list *list_env)
{
	t_list	*temp;

	temp = list_env;
	while (temp)
	{
		if (ft_strchr(temp->content, '='))
			printf("%s\n", temp->content);
		temp = temp->next;
	}
	data->exit_id = 0;
	return (0);
}
