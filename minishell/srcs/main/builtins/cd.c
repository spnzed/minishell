/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/09 11:28:18 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_info *data)
{
	if (ft_strcmp(data->cmd_line, "cd") == 0) // cd only
		chdir(data->root_path);
	else
		if (chdir(data->split_line[1]) == -1)
			printf("bash: cd: %s: No such file or directory\n", data->split_line[1]);
}
