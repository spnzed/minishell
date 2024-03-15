/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:04 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/15 16:09:04 by aaespino         ###   ########.fr       */
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

static int	get_next_redir(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>')
			return (i);
		i++;
	}
	return (i);
}

static char	*get_next_filename(char *cmd)
{
	int		i;
	int		end;
	char	*filename;
	char	*clean_redirs;
	char	**split;

	i = 0;
	while (cmd[i] == '<' || cmd[i] == '>' || ft_isspace(cmd[i]))
		i++;
	end = get_next_redir(&cmd[i], i);
	clean_redirs = ft_substr(cmd, i, end - 0);
	split = split_quotes(clean_redirs);
	if (!split)
		return (NULL);
	filename = ft_strdup(split[0]);
	ft_arrfree(split, ft_arrlen(split));
	return (filename);
}

void	get_value_infile(t_info *data, char *cmd, t_type_redir code)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &data->list_in_files);
		data->string_infile = filename;
		if (code == HEREDOC_INFILE)
		{
			data->is_heredoc = true;
			data->is_outfile = false;	
		}
		else
		{
			data->is_heredoc = false;
			data->is_outfile = true;
		}
	}
}

void	get_value_outfile(t_info *data, char *cmd, t_type_redir code)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &data->list_out_files);
		data->string_outfile = filename;
		if (code == APPEND_OUTFILE)
		{
			data->is_append = true;
			data->is_infile = false;
		}
		else
		{
			data->is_append = false;
			data->is_infile = true;
		}
	}
}
