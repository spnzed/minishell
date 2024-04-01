/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:36 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/01 14:25:56 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	char			*root;
	t_environment	*temp;

	temp = signals_env;
	while (temp->next)
	{
		if (ft_strcmp(temp->signal, "HOME") == 0)
			root = ft_strdup(temp->content);
		temp = temp->next;
	}
	return (root);
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
	data->list_exp = start_sig(order_env(data->list_env));
	data->root_path = root_pwd(data->signals_env);
	data->env = malloc_env_array(env);
	data->home = get_var_init(data->list_exp, "HOME");
	if (!data->list_env)
		return (1);
	return (0);
}
