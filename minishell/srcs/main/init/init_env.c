/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:36 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 15:57:29 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*start_env(char **env)
{
	int		i;
	t_list	*begin;
	t_list	*new;

	begin = malloc(sizeof(t_list));
	if (!begin)
		return(NULL);
	new = malloc(sizeof(t_list));
	if (!new)
		return(NULL);
	i = 0;
	while(env[i])
	{
		new = ft_lstnew(env[i]);
		ft_lstadd_back(&begin, new);
		i++;
	}
	return (begin);
}

int	init_env(t_info *data, char **env)
{
	data->list_env = start_env(env);
	if (!data->list_env)
		return (1);
	return (0);
}
