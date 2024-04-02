/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:04 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/02 16:24:10 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_add_list(char *filename, t_list **head)
{
	t_list	*temp;

	temp = ft_lstnew((void *)filename);
	ft_lstadd_back(head, temp);
	ft_lstclear(&temp, NULL);
}

int	get_next_redir(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>')
			return (i);
		i++;
	}
	return (i);
}

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

char	*get_next_filename(char *cmd)
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
