/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:30:42 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 19:50:11 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_heredoc_mul(char *name)
{
	struct stat	info;

	if (access(name, F_OK) != -1)
	{
		if (stat(name, &info) == 0)
		{
			if (S_ISREG(info.st_mode))
				unlink(name);
		}
		else
			perror("stat");
	}
}

static int	condition_mul(char *line, t_list **head, int *fd, char *name)
{
	if (ft_strcmp(line, (*head)->content) == 0)
	{
		if ((*head)->next)
		{
			close (*fd);
			remove_heredoc_mul(name);
			*fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (*fd == -1)
				return (1);
		}
		*head = (*head)->next;
	}
	else
		putstr_newl_fd(line, *fd);
	return (0);
}

void	write_heredoc(t_info *data, int fd, int nbr)
{
	t_list	*head;
	char	*line;

	head = data->list_heredocs;
	while (head)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (condition_mul (line, &head, &fd, data->heredoc_keys[nbr]) == 1)
			perror ("open");
		free (line);
	}
	close(fd);
}
