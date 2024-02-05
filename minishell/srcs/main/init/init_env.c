/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:36 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/05 19:19:00 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_environment	*start_sig(t_list *env, t_environment *sign_env)
{
	int 			i;
	char			*content;
	t_environment	*begin;

	i = -1;
	sign_env = malloc(ft_lstsize(env) * sizeof(t_environment));
	begin = sign_env;
	while (env)
	{
		content = ft_strdup(((char *)env->content));
		while (content[++i])
			if (content[i] == '=')
				break ;
		sign_env->signal = ft_substr(content, 0, i - 1);
		if (content[i] == '=')
			sign_env->content = ft_substr(content, i + 2, ft_strlen(content));
		sign_env = sign_env->next;
		env = env->next;
	}
	free(content);
	return(begin);
}

// static void	*start_sig(t_list *env, t_environment *sign_env)
// {
// 	int 	i;
// 	int 	j;
// 	char	*content;

// 	i = 0;
// 	j = 0;
// 	sign_env = malloc(ft_lstsize(env) * sizeof(t_environment));
// 	while (env)
// 	{
// 		content = ft_strdup(((char *)env->content));
// 		while (content[i])
// 		{
// 			if (content[i] == "=")
// 				break ;
// 			sign_env->signal[j] = content[i];
// 			j++;
// 			i++;
// 		}
// 		j = 0;
// 		if (content[i] == "=")
// 		{
// 			i++;
// 			while (content[i])
// 			{
// 				sign_env->content[j] = content[i];
// 				i++;
// 			}
// 		}
// 		sign_env = sign_env->next;
// 		env = env->next;
// 	}
// 	free(content);
// }

//NULO AL FINAL
static t_list	*start_env(char **env)
{
	int				i;
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

int	init_env(t_info *data, char **env)
{
	data->list_env = start_env(env);
	data->signals_env = start_sig(data->list_env, data->signals_env);
	if (!data->list_env)
		return (1);
	return (0);
}

//NULO AL PRINCIPIO
// static t_list	*start_env(char **env)
// {
// 	int		i;
// 	t_list	*begin;
// 	t_list	*new;

// 	begin = malloc(sizeof(t_list));
// 	if (!begin)
// 		return(NULL);
// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return(NULL);
// 	i = -1;
// 	while(env[++i])
// 	{
// 		new = ft_lstnew(env[i]);
// 		ft_lstadd_back(&begin, new);
// 	}
// 	return (begin);
// }