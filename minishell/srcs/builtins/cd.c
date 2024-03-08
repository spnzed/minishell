/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/08 12:51:44 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	ft_chdir(t_info	*data, char *directory)
{
	// directory = /Users/pquintan
	if (permission_dir(data, directory))
	{
		//printf("$$%s\n", directory);
		set_directory(data->list_env, "OLDPWD");
		//printf("Before chdir: %s\n", getcwd(NULL, 0));
		if (chdir(directory) == 0)
		{
		//	printf("After chdir: %s\n", getcwd(NULL, 0));
			set_directory(data->list_env, "PWD");
		}
		else
		{
			perror("chdir");
			return ;
		}
	}
}

static	void	change_home(t_info *data)
{
	char	*tmp;
	if (var_found_list(data->list_env, "HOME") == 0)
	{
		tmp = ft_after_set(get_var_list(data->list_env, "HOME")->content, '='); //ft_after_set(data->list_env->content, "=");
		ft_chdir(data, tmp); // para que haga la funcion
	}
	else
		put_error(data, data->cmd_line, "HOME not set", 0); // cambiar seguramente
}

int	ft_cd(t_info *data, char **split_cmd)
{
	char	*content;
	char 	*HOME;
	HOME = get_var_list(data->list_env, "HOME")->content + 5;
	if (split_cmd[1] && ft_strcmp(split_cmd[1], "~") == 0)
		content = ft_strdup(HOME);
	else
		content = ft_after_set(data->cmd_line, ' ');
	//No such file or directory("%s\n", content);
	if (!split_cmd[1])
		change_home(data);//change home dir + put it there
	else
	{
		if (ft_strlen(split_cmd[1]) == 0)
			return(1); //?
		ft_chdir(data, content); // le pasamos todo para que haga lo que toca
	}
	return(1);
}


// int	ft_cd(t_info *data)
// {
// 	if (ft_strcmp(data->cmd_line, "cd") == 0) // cd only
// 		chdir(data->root_path);
// 	else
// 		if (chdir(data->cmd_split[1]) == -1)
// 			printf("bash: cd: %s: No such file or directory\n", data->cmd_split[1]);
// 	return(0);
// }

