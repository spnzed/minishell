/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:29:48 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/09 20:55:39 by aaespino         ###   ########.fr       */
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

static char	*get_heredoc_key(char *cmd)
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
	if (redirs_cleaned)
		return (checker(is_quotes, redirs_cleaned));
	else 
		return (NULL);
}

static void	handle_key_name(t_info *data, char *key_name, int i)
{
	int	fd;

	fd = 0;
	data->heredoc_keys[i] = ft_strjoin(HEREDOC, key_name);
	free(key_name);
	if (data->heredoc_keys[i] != NULL)
		fd = open(data->heredoc_keys[i], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror ("open");
}

static int	heredoc_found(t_info *data, int i, int j)
{
	static int		simple;
	static int		complex;

	if (!simple)
		simple = 0;
	if (!complex)
		complex = 0;
	get_quotes_type(data->split_line[i][j], &simple, &complex);
	if (data->split_line[i][j] == '<'
		&& data->split_line[i][j - 1] == '<'
		&& !complex && !simple)
		return (1);
	return (0);
}

void	open_heredocs(t_info *data)
{
	int		i;
	int		j;
	char	*key_name;

	i = 0;
	j = 0;
	key_name = NULL;
	data->heredoc_keys = malloc(sizeof(char *) * data->cmd_nbr);
	while (data->split_line[i])
	{
		key_name = NULL;
		j = ft_strlen(data->split_line[i]) - 1;
		while (j > 0)
		{
			if (heredoc_found(data, i, j))
			{
				key_name = get_heredoc_key(&data->split_line[i][j]);
				break ;
			}
			j--;
		}
		if (key_name != NULL)
			handle_key_name(data, key_name, i);
		i++;
	}
}
