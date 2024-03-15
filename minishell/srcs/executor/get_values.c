/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:04 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/15 18:57:21 by aaespino         ###   ########.fr       */
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
	int		is_quotes;
	char	*filename;
	char	*redirs_cleaned;
	char	*quotes_cleaned;
	char	**split;

	i = 0;
	while (cmd[i] == '<' || cmd[i] == '>' || ft_isspace(cmd[i]))
		i++;
	end = get_next_redir(&cmd[i], i);
	redirs_cleaned = ft_substr(cmd, i, end - 0);
	is_quotes = num_quotes(redirs_cleaned);
	if (!is_quotes)
	{
		split = split_quotes(redirs_cleaned);
		if (!split)
			return (NULL);
		filename = ft_strdup(split[0]);
		ft_arrfree(split, ft_arrlen(split));
	}
	else
	{
		quotes_cleaned = clean_quotes(redirs_cleaned);
		filename = ft_strdup(quotes_cleaned);	
	}
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
