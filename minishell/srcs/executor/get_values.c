/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:04 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/01 19:29:56 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_value_heredoc(t_info *data, char *cmd)
{
	char	*filename;
	t_list	*aux;

	aux = data->list_heredocs;
	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &aux);
		data->list_heredocs = aux;
		data->string_infile = aux->content;
		data->is_heredoc = true;
		data->is_infile = false;
		free(filename);
	}
}

void	get_value_infile(t_info *data, char *cmd)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &data->list_in_files);
		data->string_infile = filename;
		data->is_heredoc = false;
		data->is_infile = true;
	}
}

void	get_value_outfile(t_info *data, char *cmd, t_type_redir code)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &data->list_out_files);
		data->string_outfile = filename;
		if (code == APPEND_OUTFILE)
		{
			data->is_append = true;
			data->is_outfile = false;
		}
		else
		{
			data->is_append = false;
			data->is_outfile = true;
		}
	}
}
