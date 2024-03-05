/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:35:40 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/29 18:52:21 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int little_cases(char *line)
{
	if (ft_strcmp(line, "\" \"") == 0)
	{
		ft_putstr_fd(
			"minishell: line 1: : command not found\n", 2);
		return (1);
	}
	if (ft_strcmp(line, "\"\"") == 0)
	{
		ft_putstr_fd(
			"minishell: line 1: : command not found\n", 2);	
		return (1);
	}
	return (0);
}


static int	check_pipe(char **splitted, int i, int len)
{
	if (!splitted[i])
		return(0);
	if (ft_strcmp(splitted[i], "~") == 0)
		return (0);
	if (!ft_findalnum(splitted[i]) && i == 0)
	{
		ft_arrfree(splitted, len);
		ft_putstr_fd(
			"minishell: line 1: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	return (0);
}

//aqui tenemos que estudiar los check_pipe
char	**split_cmds(t_info *data)
{
	int		i;
	int		len;
	// char	**line;
	char	**splitted;

	if (little_cases(data->cmd_line))
		exit (127);
	splitted = split_pipe(data->cmd_line, '|');
	len = ft_arrlen(splitted);
	i = 0;
	while (splitted[i])
	{
		if (check_pipe(&splitted[i], i, len))
			exit (2);
		i++;
	}
	// if (ft_strcmp(ft_strtrim(splitted[0], " "), ft_strtrim(splitted[1], " ")) == 0)
	// {
	// 	line[0] = ft_strdup(ft_strtrim(splitted[0], " "));
	// 	line[1] = NULL;
	// 	free(splitted);
	// 	return (line);
	// }
	return (splitted);
}
