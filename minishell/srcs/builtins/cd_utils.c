/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:15:30 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/23 10:59:15 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_error_msg(t_info *data, char *arg, char *str)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(str, 2);
	data->exit_id = 1;
	return (0);
}

void	set_directory(t_list **list_env, char *var)
{
	char *path;

	path = (char *)malloc(sizeof(char) * 4097);
	getcwd(path, 4097);
	//printf("&&&&%s | %s\n", var, path);
	set_var(list_env, var, path);
	if (path)
		free(path);
}

int	cd_error_file_too_long(t_info *data, char *file)
{
	char	*filename;

	filename = ft_strrchr(file, '/');
	if (filename)
	{
		if (ft_strlen(filename) > 255)
		{
			cd_error_msg(data, ": File name too long\n", file);
			return (1);
		}
	}
	else
	{
		if (ft_strlen(file) > 255)
		{
			cd_error_msg(data, ": File name too long\n", file);
			return (1);
		}
	}
	return (0);
}

static int	file_permissions(t_info *data, char *file)
{
	struct stat	buffer;

	if (access(file, R_OK) != -1 && access(file, X_OK) != -1)
	{
		if (stat(file, &buffer) == 0)
		{
			if (S_ISDIR(buffer.st_mode))
				return (1);
			else
			{
				if (ft_strlen(ft_strrchr(file, '/')) > 255)
					return (cd_error_msg(data,
							": File name too long\n", file));
				cd_error_msg(data, ": Not a directory\n", file);
			}
		}
		else
			perror("stat");
	}
	else
		cd_error_msg(data, ": Permission denied\n", file);
	return (0);
}

int	permission_dir(t_info *data, char *file)
{
	if (access(file, F_OK) != -1)
	{
		if (file_permissions(data, file))
			return (1);
	}
	else
	{
		if (cd_error_file_too_long(data, file))
			return (0);
		cd_error_msg(data, ": No such file or directory\n", file);
	}
	return (0);
}