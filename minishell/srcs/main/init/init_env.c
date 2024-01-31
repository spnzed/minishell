/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:36 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 14:26:45 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*start_env(char **env)
{
	int		i;
	t_list	*begin;
	t_list	*new;
	t_list	*str;

	str = malloc(sizeof(t_list));
	if (!str)
		return(NULL);
	begin = 0;
	i = -1;
	while(env[++i])
	{
		str->content = ft_strdup(env[i]);
		if (!str)
			exit(1);
		new = ft_lstnew(str);
		ft_lstadd_back(&begin, new);
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
