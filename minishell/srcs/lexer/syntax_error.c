/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:54:42 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/25 17:17:34 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int quotes_syntax(char *line)
{
	int i;
	int simple;
	int	complex;

	i = -1;
	simple = 0;
	complex = 0;
	if (!ft_strlen(line))
		return (0);
	while (line[++i])
	{
		if ((line[i] == '\'') && (complex == 0 || (complex == 0 && simple != 0)))
			simple++;
		else if ((line[i] == '\"') && (simple % 2 == 0 
			|| (simple == 0 && complex != 0)))
			complex++;
	}
	if ((simple == 0 && complex % 2 == 0)
		|| (simple % 2 == 0 && complex == 0)
		|| (simple % 2 == 0 && complex % 2 == 0 ))
		return (0);
	else
		return (1);
}

static int pipe_syntax(char *line, t_info *data)
{
	int	size;

	size = ft_strlen(line) - 1;
	if (size <= 0)
		return(0);
	if (line[0] == '|')
	{
		put_error_prev(data, 0, " : syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	if (line[size] == '|')
	{
		ft_putstr_fd("pipe>\n", 2);
		return (1);
	}
	return (0);
}

static int str_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int syntax_error(t_info *data)
{
    data->cmd_nbr = cmd_count(data, data->cmd_line);
	if (ft_strlen(data->cmd_line) == 0)
	{
		free(data->cmd_line);
		data->cmd_line = NULL;
		return (1);
	}
	if (str_is_space(data->cmd_line))
	{
		free(data->cmd_line);
		data->cmd_line = NULL;
		return (1);
	}
  if (data->cmd_nbr == 42)
  {
        free(data->cmd_line);
        data->cmd_line = NULL;
        return (1);
    }
    if (ft_strchr(data->cmd_line, '\'') || ft_strchr(data->cmd_line, '\"'))
    {
        if (quotes_syntax(data->cmd_line))
        {
            put_error_prev(data, 0, " : syntax error open quotes\n", 2);
            free(data->cmd_line);
            data->cmd_line = NULL;
            return (1);
        }
    }
    if (ft_strchr(data->cmd_line, '|'))
    {
        if (pipe_syntax(data->cmd_line, data) && data->cmd_nbr > 1)
        {
            free(data->cmd_line);
			data->cmd_line = NULL;
            return (1);
        }
    }
    if (ft_strchr(data->cmd_line, '>') || ft_strchr(data->cmd_line, '<'))
    {
        if (redir_syntax(data->cmd_line, data))
        {
            free(data->cmd_line);
            data->cmd_line = NULL;
            return (1);
        }
    }
    return(0);
}
