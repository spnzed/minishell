/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/21 18:44:35 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
static	void	set_directory(t_list **list_env, char *var)
{
	char *path;

	path = (char *)malloc(sizeof(char) * 4097);
	getcwd(path, 4097);
	//set_var(listenv, var, path);
	if (path)
		free(path);
}

static	void	ft_chdir(t_info	*data, char *directory)
{
	if //(permisos para directory)
	{
		set_directory(data->list_env, "OLDPWD");
		if (chdir(directory) == 0)
			set_directory(data->list_env, "PWD");
		else
			//put_error("chdir");
		// (void)data;?
	}
}

static	void	change_home(t_info *data)
{
	char	*tmp;
	if //("HOME" esta en data->list_env)
	{
		tmp = //content de home
		// ft_chdir(data, tmp); para que haga la funcion
	}
	else
		put_error(data, data->cmd_line, "HOME not set", 0); // cambiar seguramente
}

int	ft_cd(t_info *data)
{
	char	*content;

	content = ft_after_set(data->cmd_line, ' ');
	//printf("%s\n", content);
	if (!content)
		change_home(data);//change home dir + put it there
	else
	{
		if (ft_strlen(content) == 0)
			return(1) //?
		// ft_chdir(data, content); // le pasamos todo para que haga lo que toca
	}
	return(1);
}
*/

int	ft_cd(t_info *data)
{
	if (ft_strcmp(data->cmd_line, "cd") == 0) // cd only
		chdir(data->root_path);
	else
		if (chdir(data->cmd_split[1]) == -1)
			printf("bash: cd: %s: No such file or directory\n", data->cmd_split[1]);
	return(0);
}

