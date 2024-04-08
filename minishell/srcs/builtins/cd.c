/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/08 17:06:21 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	ft_chdir(t_info	*data, char *directory, char **split_cmd)
{
	if (permission_dir(data, directory, split_cmd))
	{
		set_directory(data->list_env, "OLDPWD");
		if (chdir(directory) == 0)
			set_directory(data->list_env, "PWD");
		else
		{
			perror("chdir");
			return ;
		}
		data->exit_id = 0;
	}
}

static void	change_home(t_info *data, char **split_cmd)
{
	if (var_found_list(data->list_env, "HOME") == 0)
		ft_chdir(data, data->home, split_cmd);
	else
		put_error(data, data->cmd_line, "HOME not set", 0);
}

int	cd_builtin(t_info *data, char **split_cmd)
{
	char	*content;

	content = NULL;
	if (split_cmd[1] && ft_strcmp(split_cmd[1], "~") == 0)
		content = ft_strdup(data->home);
	else if (split_cmd[1])
		content = ft_strdup(split_cmd[1]);
	if (!split_cmd[1] || ft_strchr(split_cmd[1], '\\'))
		change_home(data, split_cmd);
	else
	{
		if (ft_strlen(split_cmd[1]) == 0)
			return (1);
		ft_chdir(data, content, split_cmd);
	}
	if (content != NULL)
		free(content);
	return (1);
}
