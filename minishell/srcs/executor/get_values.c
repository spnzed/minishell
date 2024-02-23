/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:04 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/23 17:45:24 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redir_add_list(char *filename, t_list **head)
{
	t_list	*temp;

	temp = ft_lstnew((char *)filename);
	if (!temp)
		return ;
	ft_lstadd_back(head, temp);
}

static char	*get_next_filename(char *cmd)
{
	char	**split;
	char	*filename;

	while (*cmd == '<' || *cmd == '>')
		cmd++;
	split = split_quotes(cmd);
	if (!split)
		return (NULL);
	filename = ft_strdup(split[0]);
	ft_arrfree(split, ft_arrlen(split));
	return (filename);
}

void	get_value_infile(t_info *data, char *cmd)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &data->list_in_files);
		data->in_file = filename;
	}
}

void	get_value_outfile(t_info *data, char *cmd)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &data->list_out_files);
		data->out_file = filename;
		data->is_append = 0;
	}
}

void	get_value_append(t_info *data, char *cmd)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &data->list_out_append);
		data->out_file = filename;
		data->is_append = 1;
	}
}

void	get_value_heredoc(t_info *data, char *cmd)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &data->list_heredocs);
		data->in_file = HEREDOC;
		data->is_heredoc = 1;
	}
}

