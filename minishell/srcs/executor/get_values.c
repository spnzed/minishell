/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:04 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 15:18:36 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_redir_list	*ft_redir_lstnew(void *content, t_type_redir type)
{
	t_redir_list	*new_node;

	new_node = malloc(sizeof(t_redir_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->type = type;
	return (new_node);
}

static void	ft_redir_lstadd_back(t_redir_list **lst, t_redir_list *new)
{
	t_redir_list	*aux;

	aux = *lst;
	if (*lst)
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	else
	{
		*lst = new;
		((t_redir_list *)lst)->next = NULL;
	}
}

//
static void	ft_redir_lstdelone(t_redir_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del)
		{
			del(lst->content);
			free(lst);
		}
	}
}


//
static void	ft_redir_lstclear(t_redir_list **lst, void (*del)(void*))
{
	t_redir_list	*aux;

	if (!*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		ft_redir_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = 0;
}

//

static void	redir_add_list_out(char *filename, t_redir_list **head, t_type_redir type)
{
	t_redir_list	*temp;

	temp = ft_redir_lstnew((void *)filename, type);
	ft_redir_lstadd_back(head, temp);
	ft_redir_lstclear(&temp, NULL);
}

void	get_value_heredoc(t_info *data, char *cmd)
{
	char	*filename;
	t_list	*aux;

	aux = data->list_heredocs;
	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &aux);
		data->list_heredocs = aux;
		data->string_infile = aux->content;
		data->is_heredoc = true;
		data->is_infile = false;
	}
}

void	get_value_infile(t_info *data, char *cmd)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list(filename, &data->list_in_files);
		data->string_infile = filename;
		data->is_heredoc = false;
		data->is_infile = true;
	}
}

void	get_value_outfile(t_info *data, char *cmd, t_type_redir code)
{
	char	*filename;

	filename = get_next_filename(cmd);
	if (filename)
	{
		redir_add_list_out(filename, &data->list_out_files, code);
		data->string_outfile = filename;
		if (code == APPEND_OUTFILE)
		{
			data->is_append = true;
			data->is_outfile = false;
		}
		else
		{
			data->is_append = false;
			data->is_outfile = true;
		}
	}
}
