/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_to_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:02:41 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/28 14:43:31 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prepare_to_exec(t_info *data)
{
	static int	x;

	if (x)
		free_array(data->split_line);
	data->split_line = split_cmds(data);
	data->from_file = 0;
	data->list_in_files = NULL;
	data->list_out_files = NULL;
	data->list_heredocs = NULL;
	data->string_infile = 0;
	data->string_outfile = 0;
	data->string_overwrite = 0;
	data->string_append = 0;
	data->is_infile = false;
	data->is_outfile = false;
	data->is_append = false;
	data->is_heredoc = false;
	x++;
}

void	prepare_to_exec_one(t_info *data)
{
	static int	x;

	if (x)
	{
		free(data->cmd_clean);
		free_array(data->one_cmd);
	}
	data->from_file = 0;
	data->list_in_files = NULL;
	data->list_out_files = NULL;
	data->list_heredocs = NULL;
	data->string_infile = 0;
	data->string_outfile = 0;
	data->string_overwrite = 0;
	data->string_append = 0;
	data->is_infile = false;
	data->is_outfile = false;
	data->is_append = false;
	data->is_heredoc = false;
	get_redirections(data->cmd_line, data);
	if (data->list_in_files || data->list_out_files
		|| data->list_heredocs)
		data->cmd_clean = clean_redir(data->cmd_line);
	else
		data->cmd_clean = ft_strdup(data->cmd_line);
	data->one_cmd = split_quotes(data->cmd_clean);
	x++;
}
