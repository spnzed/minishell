/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:15:30 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/28 14:24:58 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_error_msg(t_info *data, char *arg, char *str)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd((ft_strtrim(ft_strtrim(str, "\'"), "\"")), 2);
	ft_putstr_fd(arg, 2);
	data->exit_id = 1;
	return (0);
}

void	set_directory(t_list *list_env, char *var)
{
	char	*path;

	path = (char *)malloc(sizeof(char) * 4097);
	getcwd(path, 4097);
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

	if (access(file, R_OK) != -1)
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

static int	check_quotes_arg(char **split_cmd)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	while (split_cmd[x])
	{
		while (split_cmd[x][y])
		{
			if (split_cmd[x][y] != '\'' && split_cmd[x][y] != '\"')
				return (1);
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}

int	permission_dir(t_info *data, char *file, char **split_cmd)
{
	if (access(file, F_OK) != -1)
	{
		if (file_permissions(data, file))
			return (1);
	}
	else
	{
		if (ft_strlen(ft_strtrim(ft_strtrim(file, "\'"), "\"")) == 0)
			return (0);
		if (check_quotes_arg(split_cmd) == 0)
			return (0);
		if (cd_error_file_too_long(data, file))
			return (0);
		if (ft_strchr(file, '/'))
			cd_error_msg(data, ": Not a directory\n", file);			
		cd_error_msg(data, ": No such file or directory\n", file);
	}
	return (0);
}
/*
	este caso igual que si pones muchas mas comillas cd "" ""
	se puede solucionar en el if este
			if (ft_strlen(ft_strtrim(ft_strtrim(file, "\'"), "\"")) == 0)
			return(0);
	pero habria que hacer una funcion para que mientras solo haya comillas 
	pues se lo salte
*/