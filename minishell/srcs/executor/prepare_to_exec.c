/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_to_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:02:41 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/05 19:22:10 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prepare_to_exec(t_info *data)
{
	static int	x;

	if (x)
		free_array(data->split_line);
	data->split_line = split_cmds(data);
	if (data->split_line == NULL)
		return (1);
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
	return (0);
}

static void	init_var(t_info *data)
{
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
}

void	prepare_to_exec_one(t_info *data)
{
	static int	x;

	if (x)
		free_array(data->one_cmd);
	init_var(data);
	get_redirections(data->cmd_line, data);
	if (data->list_in_files || data->list_out_files
		|| data->list_heredocs)
		data->cmd_clean = clean_redir(data->cmd_line);
	else
		data->cmd_clean = ft_strdup(data->cmd_line);
	data->one_cmd = split_quotes(data->cmd_clean);
	free(data->cmd_clean);
	x++;
}
