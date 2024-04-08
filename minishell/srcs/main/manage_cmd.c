/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   manage_cmd.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pquintan <pquintan@student.42barcelona.	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/31 17:38:55 by aaespino		  #+#	#+#			 */
/*   Updated: 2024/03/28 14:43:43 by pquintan		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

static int	print_space_error(t_info *data, char *line)
{
	int	i;
	int	start;

	i = 0;
	if (line[i] == '\"' | line[i] == '\''
		&& (line[ft_strlen(line) - 1] == '\"'
			|| line[ft_strlen(line) - 1] == '\''))
		i++;
	start = i;
	while (i < ft_strlen(line) - 1 || i == 0)
	{
		if (!ft_isspace((line[i])))
			return (0);
		i++;
	}
	i = start;
	ft_putstr_fd("minishell: line 1: ", 2);
	while (i < ft_strlen(line) - 1)
	{
		ft_putstr_fd(" ", 2);
		i++;
	}
	ft_putstr_fd(": command not found\n", 2);
	data->exit_id = 127;
	return (1);
}

static int	little_cases(t_info *data, char *line)
{
	if (line[0] == ' ')
	{
		while (*line == ' ')
			line++;
	}
	if (print_space_error(data, line))
		return (1);
	if (ft_strcmp(line, "\"\"") == 0)
	{
		ft_putstr_fd(
			"minishell: line 1: : command not found\n", 2);
		data->exit_id = 127;
		return (1);
	}
	return (0);
}

static void	expander(t_info *data)
{
	if (ft_strchr(data->cmd_line, '$'))
	{
		while (comprove_var(data->cmd_line))
			data->cmd_line = parse_var(data);
	}
}

static void	executor(t_info *data)
{
	if (data->cmd_line)
	{
		if (data->cmd_nbr == 1)
		{
			if (little_cases(data, data->cmd_line))
				return ;
			prepare_to_exec_one(data);
			exec_one_cmd(data);
		}
		else if (data->cmd_nbr > 1)
		{
			if (prepare_to_exec(data))
				exec_cmds(data);
		}
	}
}

int	manage_cmd(t_info *data)
{
	syntax_error(data);
	expander(data);
	executor(data);
	return (0);
}
