/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect_mul.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:38:43 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/09 19:42:37 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_file(char *file, int open_code, int std_mode, int num)
{
	int	fd;

	if (num > 0)
		fd = open(file, open_code, num);
	else
		fd = open(file, open_code);
	if (fd == -1)
	{
		ft_putstr_fd ("minishell: ", 2);
		ft_putstr_fd ("line 1: ", 2);
		perror (file);
		exit(1);
	}
	if (dup2(fd, std_mode) == -1)
	{
		perror("dup2");
		close (fd);
		exit(1);
	}
}

static void	build_files(t_info *data, int i)
{
	if (ft_strlen(data->string_infile) > 0)
	{
		if (!data->is_heredoc)
			handle_file(data->string_infile, O_RDONLY, STDIN_FILENO, 0);
		if (data->heredoc_keys[i] && ft_strnstr(data->split_line[i], "<<",
				ft_strlen(data->split_line[i])))
			handle_file(data->heredoc_keys[i], O_RDONLY, STDIN_FILENO, 0);
	}
	if (ft_strlen(data->string_outfile) > 0)
	{
		if (data->is_append)
			handle_file(data->string_outfile,
				O_WRONLY | O_CREAT | O_APPEND, STDOUT_FILENO, 0644);
		else
			handle_file(data->string_outfile,
				O_WRONLY | O_CREAT | O_TRUNC, STDOUT_FILENO, 0644);
	}
}

int	handle_redirect_mul(t_info *data, int i)
{
	if (data->cmd_nbr == 1)
		if (comprove_heredoc(data))
			return (1);
	if (comprove_stdout(data))
		return (1);
	if (comprove_stdin(data))
		return (1);
	build_files(data, i);
	remove_heredoc();
	if (data->list_in_files)
		free_list(data->list_in_files);
	if (data->list_out_files)
		free_redir_list(data->list_out_files);
	if (data->list_heredocs)
		free_list(data->list_heredocs);
	return (0);
}
