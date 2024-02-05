/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/05 13:07:08 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_info *data)
{
	t_info *temp;
	temp = data;
	char *str = "PWD=";
	while (temp->list_env)
	{
		while (temp->list_env->content)
		{
			if (ft_strcmp(str, temp->list_env->content)) // check if found it exits
			{
				printf("only after 'PWD='");
				return(0);
			}
			temp->list_env = temp->list_env->next;
		}
	}
	return(1); // PWD not found
}
// Funcion prototipo