/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:21:19 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/10 12:43:13 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_redirs_heredoc(char *cmd, int i, t_info *data)
{
	int		simple;
	int		complex;

	simple = 0;
	complex = 0;
	while (cmd[++i])
	{
		get_quotes_type(cmd[i], &simple, &complex);
		if (cmd[i] == '<' && cmd[i + 1] == '<'
			&& !complex && !simple)
			get_value_heredoc(data, &cmd[++i]);
	}
}

static int	comprove_heredoc_mul(t_info *data, char *cmd, int nbr)
{
	int		fd;

	signal(SIGINT, signal_handler_heredoc);
	signal(SIGQUIT, signal_handler_heredoc);
	fd = open(data->heredoc_keys[nbr], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (perror ("open"), 1);
	get_redirs_heredoc(cmd, -1, data);
	return (fd);
}

void	handle_heredoc_pipe(t_info *data)
{
	int		i;
	int		fd;

	i = -1;
	fd = 0;
	open_heredocs(data);
	if (data->heredoc_keys != NULL)
	{
		while (++i < data->cmd_nbr)
		{
			if (data->list_heredocs)
				ft_lstclear(&data->list_heredocs, free);
			if (!ft_strnstr(data->split_line[i], "<<",
					ft_strlen(data->split_line[i])))
				data->heredoc_keys[i] = ft_strdup ("PLACEHOLDER");
			else
			{
				fd = comprove_heredoc_mul(data, data->split_line[i], i);
				write_heredoc(data, fd, i);
				close(fd);
			}
		}
	}
	else
		return ;
}
