/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:28:25 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 17:31:19 by aaespino         ###   ########.fr       */
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

void	redir_add_list_out(char *filename, t_redir_list **head,
			t_type_redir type)
{
	t_redir_list	*temp;

	temp = ft_redir_lstnew((void *)filename, type);
	ft_redir_lstadd_back(head, temp);
	ft_redir_lstclear(&temp, NULL);
}
