/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:38:43 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/19 19:38:40 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int handle_redirect(t_info *data)
{
	if (data->out_files || data->out_append && files_out(data))
		return (1);
	if (data->in_files && files_in(&data->in_files))
		return (1);
	return (0);
	if (data->is_heredoc)
		handle_heredoc(data);
}
	if (data->infile)
		from_file_top(data->infile);
	if (data->outfile && !data->is_append)
		in_file_top(data->outfile);
	else if (data->outfile && data->is_append)
		in_file_bottom(data->outfile);
	ft_remove_heredoc_file();
	return (0);