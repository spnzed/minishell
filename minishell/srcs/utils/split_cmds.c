/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:35:40 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/11 17:39:16 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	little_cases(char *line)
{
	if (ft_strcmp(line, "\" \"") == 0)
	{
		ft_putstr_fd(
			"minishell: line 1: : command not found\n", 2);
		return (1);
	}
	if (ft_strcmp(line, "\"\"") == 0)
	{
		ft_putstr_fd("minishell: line 1: : command not found\n", 2);
		return (1);
	}
	return (0);
}

static int	check_pipe(char *splitted, int i)
{
	if (!splitted)
		return (0);
	if (ft_strcmp(splitted, "~") == 0)
		return (0);
	if (!ft_findalnum(splitted) && i == 0)
	{
		ft_putstr_fd("minishell: line 1: ", 2);
		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	return (0);
}

char	**split_cmds(t_info *data)
{
	int		i;
	int		len;
	char	**splitted;

	if (little_cases(data->cmd_line))
		exit (127);
	splitted = split_pipe(data->cmd_line, '|');
	len = ft_arrlen(splitted);
	i = 0;
	while (splitted[i])
	{
		if (check_pipe(splitted[i], i))
			exit (2);
		i++;
	}
	return (splitted);
}
