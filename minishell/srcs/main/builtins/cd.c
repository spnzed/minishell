/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/07 18:31:24 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_info *data)
{
	//char s[100];

	//printf("before: %s\n", getcwd(s, 100));
	if (ft_strcmp(data->cmd_line, "cd") == 0) // cd only
		chdir(data->root_path);
	else if (ft_strcmp(data->cmd_line, "cd ..") == 0) // cd .. (directory before)
		chdir("..");
	// else if (data->cmd_line)// starts with / (absolute path->starts from root)
	// {
		
	// }
	else // (relative path->starts from current path)
		printf("NO!");
	
	//printf("now: %s\n", getcwd(s, 100));
}
// chdir getcwd