/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:38:51 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 20:39:50 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_heredoc(void)
{
	struct stat	info;

	if (access(HEREDOC, F_OK) != -1)
	{
		if (stat(HEREDOC, &info) == 0)
		{
			if (S_ISREG(info.st_mode))
				unlink(HEREDOC);
		}
		else
			perror("stat");
	}
}

void	putstr_newl_fd(char *str, int fd)
{
	if (!str || !fd)
		return ;
	ft_putstr_fd (str, fd);
	write (fd, "\n", 1);
}

static int	condition(char *line, t_list **head, int *fd)
{
	if (ft_strcmp(line, (*head)->content) == 0)
	{
		if ((*head)->next)
		{
			close (*fd);
			remove_heredoc();
			*fd = open(HEREDOC, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (*fd == -1)
				return (1);
		}
		*head = (*head)->next;
	}
	else
		putstr_newl_fd(line, *fd);
	return (0);
}

int	comprove_heredoc(t_info *data)
{
	int		fd;
	char	*line;
	t_list	*head;

	signal(SIGINT, signal_handler_heredoc);
	signal(SIGQUIT, signal_handler_heredoc);
	fd = open(HEREDOC, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (perror ("open"), 1);
	head = data->list_heredocs;
	while (head)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (condition (line, &head, &fd) == 1)
			return (perror ("open"), 1);
		free (line);
	}
	close(fd);
	return (0);
}
