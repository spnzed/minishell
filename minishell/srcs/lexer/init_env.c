/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:36 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/01 16:07:55 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_environment	*start_sig(t_list *env)
{
	int 			i;
	t_environment	*begin;
	t_environment	*new_env;

	begin = NULL;
	while (env)
	{
		new_env = ft_envnew(((char *)env->content));
		i = -1;
		if (!new_env)
		{
			ft_envclear(&begin, free);
			return (NULL);
		}
		while (new_env->full_line[++i])
			if (new_env->full_line[i] == '=')
				break ;
		new_env->signal = ft_substr(new_env->full_line, 0, i);
		if (new_env->full_line[i] == '=')
			new_env->content = ft_substr(new_env->full_line, i + 1, ft_strlen(new_env->full_line));
		if (!begin)
			begin = new_env;	
		else
			ft_envadd_back(&begin, new_env);
		env = env->next;
	}
	return(begin);
}

t_list	*order_env(t_list *env)
{
	t_list *list_order;
	int len_list;
	int index;
	t_list *temp;
	t_list *tempvar;

	list_order = ft_copy_list(env); // copy list
	len_list = ft_lstsize(list_order);
	index = 0;

	while (index < len_list)
	{
		temp = list_order;
		while (temp->next != NULL)
		{
			if ((ft_strcmp(temp->content, temp->next->content)) > 0)
			{
				tempvar = temp->next;
				temp->next = temp->next->next;
				tempvar->next = list_order;
				list_order = tempvar;
			}
			else
				temp = temp->next;
		}
		index++;
	}

	return (list_order);
}

static t_list	*start_env(char **env)
{
	int		i;
	t_list	*begin;
	t_list	*new;

	begin = NULL;
	i = -1;
	while (env[++i])
	{
		new = ft_lstnew(env[i]);
		if (!new)
		{
			ft_lstclear(&begin, free);
			return (NULL);
		}
		if (!begin)
			begin = new;	
		else
			ft_lstadd_back(&begin, new);
	}
	return (begin);
}

static char	*root_pwd(t_environment *signals_env)
{
	t_environment *temp;
	char *root;

	temp = signals_env;
	
	while (temp->next)
	{
		if (ft_strcmp(temp->signal, "HOME") == 0)
			root = ft_strdup(temp->content);
		temp = temp->next;
	}
	// printf("root: %s\n", root);
	return(root);
}

char	**malloc_env_array(char **env)
{
	int		i;
	char	**array;

	i = -1;
	array = malloc(sizeof(char *) * (ft_arrlen(env) + 1));
	while (env[++i])
		array[i] = ft_strdup(env[i]);
	array[i] = NULL;
	return (array);
}

int	init_env(t_info *data, char **env)
{
	data->list_env = start_env(env);
	data->signals_env = start_sig(data->list_env);
	data->list_exp = start_sig(order_env(data->list_env)); // la idea es que primero ordene y luego lo divida
	data->root_path = root_pwd(data->signals_env);
	data->env = malloc_env_array(env);
	if (!data->list_env)
		return (1);
	return (0);
}
