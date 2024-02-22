/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_route.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:09:59 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/22 18:52:48 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handle_path(t_environment *lst_env, char *cmd, char *line)
{
	t_environment *tmp;

	tmp = NULL;
	if (!ft_findalnum(cmd))
		return (NULL);
	if (var_found(lst_env, "PATH"))
	{
		tmp = var_export(lst_env, "PATH");
		line = tmp->content;
		return (line);
	}
	else
		return (NULL);
}

static char	**handle_route(char *line, char *cmd)
{
	char	**route;
	char	**tmp;

	tmp = ft_split(line, ':');
	route = add_cmd(tmp, cmd);
	return (route);
}

/*
	while (route[++i] && access(route[i], F_OK) == -1)
		
		access comprueba si un archivo existe
		
		F_OK se pasa como segundo argumento para indicar 
		que estamos verificando solo la existencia del archivo.

			Queremos comprobar que no existe, usando == -1
		
		Es decir quuiere dejar la iteracion hasta que encuentre
		un archivo que existe
*/
char	*find_cmd_route(t_environment *lst_env, char *cmd)
{
	int		i;
	char	*ret;
	char	*line;
	char	**route;

	i = -1;

	
	line = handle_path(lst_env, cmd, NULL);
	if (!line)
		return (NULL);
	route = handle_route(line, cmd);
	
	while (route[++i] && access(route[i], F_OK) == -1)
		;
	if (!route[i])
	{
		ret	= ft_strtrim(cmd, " ");
		//ft_arrfree(route, ft_arrlen(route));
		return (ret);
	}
	ret = ft_strdup(route[i]);
	//ft_arrfree(route, ft_arrlen(route) - 1);
	return (ret);
}
