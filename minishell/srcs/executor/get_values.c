/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:04 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/11 15:20:24 by aaespino         ###   ########.fr       */
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
	int		i;
	char	*filename;
	char	**split;

	i = 0;
	while (cmd[i] == '<' || cmd[i] == '>')
		i++;
	split = split_quotes(&cmd[i]);
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
		data->string_infile = filename;
	}
}

void	get_value_outfile(t_info *data, char *cmd)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &data->list_out_files);
		data->string_outfile = filename;
		data->is_outfile = false;
	}
}

void	get_value_append(t_info *data, char *cmd)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &data->list_out_append);
		data->string_append = filename;
		data->is_append = true;
	}
}

void	get_value_heredoc(t_info *data, char *cmd)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &data->list_heredocs);
		data->string_heredoc = HEREDOC;
		data->is_heredoc = true;
	}
}
