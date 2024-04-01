/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:36 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/01 14:55:41 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	loop_part_two(t_environment **new_env, int i,
	t_environment **begin, t_list **env)
{
	(*new_env)->signal = ft_substr((*new_env)->full_line, 0, i);
	if ((*new_env)->full_line[i] == '=')
		(*new_env)->content = ft_substr((*new_env)->full_line, i + 1,
				ft_strlen((*new_env)->full_line));
	if (!(*begin))
		*begin = *new_env;
	else
		ft_envadd_back(begin, *new_env);
	*env = (*env)->next;
}

t_environment	*start_sig(t_list *env)
{
	int				i;
	static int		x;
	t_environment	*begin;
	t_environment	*new_env;
	t_list			*env_head;

	env_head = env;
	begin = NULL;
	while (env)
	{
		new_env = ft_envnew(((char *)env->content));
		i = -1;
		if (!new_env)
			return (ft_envclear(&begin, free), NULL);
		while (new_env->full_line[++i])
			if (new_env->full_line[i] == '=')
				break ;
		loop_part_two(&new_env, i, &begin, &env);
	}
	if (x == 1)
		free_list(env_head);
	x++;
	return (begin);
}

static void	swap(t_list **temp, t_list **list_order)
{
	t_list	*tempvar;

	tempvar = (*temp)->next;
	(*temp)->next = (*temp)->next->next;
	tempvar->next = *list_order;
	*list_order = tempvar;
}

t_list	*order_env(t_list *env)
{
	int		index;
	int		len_list;
	t_list	*temp;
	t_list	*list_order;

	list_order = ft_copy_list(env);
	len_list = ft_lstsize(list_order);
	index = 0;
	while (index < len_list)
	{
		temp = list_order;
		while (temp->next != NULL)
		{
			if ((ft_strcmp(temp->content, temp->next->content)) > 0)
				swap(&temp, &list_order);
			else
				temp = temp->next;
		}
		index++;
	}
	return (list_order);
}
