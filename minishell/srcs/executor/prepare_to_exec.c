/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_to_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:02:41 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/07 15:11:45 by pquintan         ###   ########.fr       */
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

void prepare_to_exec(t_info *data)
{
	data->split_line = split_cmds(data);
	data->file_overwrite = 0;
	data->file_append = 0;
	data->from_file = 0;
	data->list_in_files = NULL;
	data->list_out_files = NULL;
	data->list_out_append = NULL;
	data->is_append = false;
	data->is_heredoc = false;
}

void prepare_to_exec_one(t_info *data)
{
	if (little_cases(data->cmd_line))
		exit (127);
	data->file_overwrite = 0;
	data->file_append = 0;
	data->from_file = 0;
	data->list_in_files = NULL;
	data->list_out_files = NULL;
	data->list_out_append = NULL;
	data->is_append = false;
	data->is_heredoc = false;
	get_redirections(data->cmd_line, data);
	if (data->list_in_files || data->list_out_files
		 || data->list_out_append || data->list_heredocs)
		data->cmd_clean = clean_redir(data->cmd_line);
	else
		data->cmd_clean = ft_strdup(data->cmd_line);
	data->one_cmd = split_quotes(data->cmd_clean);
}
