/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:48 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/05 17:37:23 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtins(t_info *data)
{
	if (ft_strcmp(data->cmd_line, "env") == 0)
		ft_env(&data->list_env);
	else if (ft_strcmp(data->cmd_line, "pwd") == 0)
		ft_pwd();

	// else
	// 	printf("command error\n"); // arreglar error
	/*while(data->cmd_line)
	{
		if (is_env(data->cmd_line, len))
			ft_env(data);
		else
			printf("command error\n"); // arreglar error
		//exit(0);
	}*/
}