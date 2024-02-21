/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_to_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:02:41 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/21 18:20:19 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void prepare_to_exec(t_info *data)
{
	data->split_line = split_cmds(data);
	data->file_overwrite = 0;
	data->file_append = 0;
	data->from_file = 0;
	data->out_files = 0;
	data->out_append = 0;
	data->in_files = 0;
	data->is_append = false;
	data->is_heredoc = false;
}
