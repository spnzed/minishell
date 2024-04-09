/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:15:30 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/28 16:33:01 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	cd_error_msg(t_info *data, char *arg, char *str)
{
	char	*simple_aux;
	char	*complex_aux;

	simple_aux = ft_strtrim(str, "\'");
	complex_aux = ft_strtrim(simple_aux, "\"");
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(complex_aux, 2);
	ft_putstr_fd(arg, 2);
	data->exit_id = 1;
	free(simple_aux);
	free(complex_aux);
	return (0);
}
