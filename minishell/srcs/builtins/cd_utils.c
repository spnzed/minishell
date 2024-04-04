/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:15:30 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/04 19:25:37 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static int	free_return(char *simple, char *complex)
{
	free(simple);
	free(complex);
	return (1);
}

static int	else_permission(t_info *data, char *file, char **split_cmd)
{
	char	*simple;
	char	*complex;

	simple = ft_strtrim(file, "\'");
	complex = ft_strtrim(simple, "\"");
	if (ft_strlen(complex) == 0)
		return (free_return(simple, complex));
	if (check_quotes_arg(split_cmd) == 0)
		return (free_return(simple, complex));
	if (cd_error_file_too_long(data, file))
		return (free_return(simple, complex));
	if (ft_strchr(file, '/'))
		cd_error_msg(data, ": Not a directory\n", file);
	cd_error_msg(data, ": No such file or directory\n", file);
	free(simple);
	free(complex);
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
		if (else_permission(data, file, split_cmd) == 1)
			return (0);
	return (0);
}
