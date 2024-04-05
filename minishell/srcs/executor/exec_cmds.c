/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:27:44 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/05 21:39:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*checker(int is_quotes, char *redirs_cleaned)
{
	char	*quotes_cleaned;
	char	**split;
	char	*filename;


	filename = NULL;
	if (!is_quotes)
	{
		split = split_quotes(redirs_cleaned);
		if (!split)
		{
			free(redirs_cleaned);
			return (NULL);
		}
		filename = ft_strdup(split[0]);
		ft_arrfree(split, ft_arrlen(split));
	}
	else
	{
		quotes_cleaned = clean_quotes(redirs_cleaned);
		filename = ft_strdup(quotes_cleaned);
	}
	free(redirs_cleaned);
	return (filename);
}

char	*get_heredoc_key(char *cmd)
{
	int		i;
	int		end;
	int		is_quotes;
	char	*redirs_cleaned;

	i = 0;
	while (cmd[i] == '<' || cmd[i] == '>' || ft_isspace(cmd[i]))
		i++;
	end = get_next_redir(&cmd[i], i);
	redirs_cleaned = ft_substr(cmd, i, end - 0);
	is_quotes = num_quotes(redirs_cleaned);
	return (checker(is_quotes, redirs_cleaned));
}

static void	open_heredocs(t_info *data)
{
	int		i;
	int		j;
	int		fd;
	int		simple;
	int		complex;
	char	*key_name;

	i = 0;
	j = 0;
	simple = 0;
	complex = 0;
	key_name = NULL;
	data->HEREDOC_keys = malloc(sizeof(char *) * data->cmd_nbr);
	while (data->split_line[i])
	{
		j = ft_strlen(data->split_line[i]) - 1;
		while (data->split_line[i][j])
		{
			get_quotes_type(data->split_line[i][j], &simple, &complex);
			if (data->split_line[i][j] == '<' && data->split_line[i][j - 1] == '<'
				&& !complex && !simple)
			{
				key_name = get_heredoc_key(&data->split_line[i][j]);
				break ;
			}
			j--;
		}
		if (key_name != NULL)
		{
			data->HEREDOC_keys[i] = ft_strjoin(HEREDOC, key_name);
			fd = open(data->HEREDOC_keys[i], O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
				perror ("open");
		}
		i++;
	}
}

static void	wait_childs(t_info *data)
{
	int	nbr;
	int	pid;
	int	status;

	nbr = data->cmd_nbr;
	while (nbr--)
	{
		pid = waitpid(-1, &status, 0);
		if (nbr == 0 && WIFSIGNALED(status))
		{
			status += 128;
			catch_signal(data, status, 0);
		}
		else if (pid == data->pid)
			if (WIFEXITED(status))
				data->exit_id = WEXITSTATUS(status);
	}
	return ;
}

static void	handle_heredoc(char *file, int open_code, int std_mode)
{
	int	fd;

	fd = open(file, open_code);
	if (fd == -1)
	{
		dprintf (2, "minishell: ");
		dprintf (2, "line 1: ");
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

int	exec_cmds(t_info *data)
{
	int	i;

	i = -1;
	signal(SIGINT, SIG_IGN);
	if (data->cmd_nbr > 1)
	{
		open_heredocs(data);
		while (++i < data->cmd_nbr)
		{
			comprove_heredoc_mul(data, data->split_line[i], i);
			handle_heredoc(data->HEREDOC_keys[i], O_RDONLY, STDIN_FILENO);
		}
	}
	i = -1;
	while (++i < data->cmd_nbr)
	{
		pipe(data->fd);
		signal(SIGINT, SIG_IGN);
		data->pid = fork();
		if (call_childs(data, i))
			parent_process(data);
	}
	wait_childs(data);
	return (0);
}
