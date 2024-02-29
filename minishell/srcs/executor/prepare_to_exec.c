/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_to_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:02:41 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/26 19:39:24 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
