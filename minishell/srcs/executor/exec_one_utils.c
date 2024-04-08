/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:15:29 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 17:21:05 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isstrprint(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_isprint(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	filter_one_cmd(t_info *data, char **splitted_cmd)
{
	if (!splitted_cmd[0])
		return ;
	if (ft_strcmp(splitted_cmd[0], " ") == 0)
		put_error(data, " line 1: ", ": command not found\n", 127);
	if (ft_strcmp(splitted_cmd[0], "~") == 0)
	{
		ft_putstr_fd("minishell: line 1: ", 2);
		ft_putstr_fd(data->home, 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit (126);
	}
}

bool	comprove_redirs(t_info *data)
{
	if (!data->is_outfile && !data->is_heredoc
		&& !data->is_infile && !data->is_append)
		return (false);
	return (true);
}

static void	print_last_error(t_info *data, int i)
{
	ft_putstr_fd("minishell: line 1: ", 2);
	while (ft_isspace(data->one_cmd[0][i]))
	{
		ft_putstr_fd(" ", 2);
		i++;
	}
	if ((data->one_cmd[0][i] == '\'' || data->one_cmd[0][i] == '\"'))
		i++;
	ft_putstr_fd (&data->one_cmd[0][i], 2);
	ft_putstr_fd (": command not found\n", 2);
	data->exit_id = 127;
	exit (127);
}

void	last_error(t_info *data)
{
	int	size;
	int	i;

	i = 1;
	size = ft_strlen(data->one_cmd[0]);
	if (ft_isspace(data->one_cmd[0][i])
		&& ((data->one_cmd[0][0] == '\'' && data->one_cmd[0][size -1] != '\'')
		|| (data->one_cmd[0][0] == '\"' && data->one_cmd[0][size -1] != '\"')))
		print_last_error(data, i);
	if (data->one_cmd[0][0] == '\'' && data->one_cmd[0][size -1] == '\'')
		put_error(data, ft_strtrim(data->one_cmd[0], "\'"),
			": command not found\n", 127);
	if (data->one_cmd[0][0] == '\"' && data->one_cmd[0][size -1] == '\"')
		put_error(data, ft_strtrim(data->one_cmd[0], "\""),
			": command not found\n", 127);
	else
		put_error(data, data->one_cmd[0], ": command not found\n", 127);
}
