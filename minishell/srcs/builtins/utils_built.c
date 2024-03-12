/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_built.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:51:09 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/12 16:26:42 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_bigger_maxll(char *str)
{
	int	negative;

	negative = 0;
	if (str[0] == '-')
		negative = 1;
	if (ft_strcmp(str, "-9223372036854775808") == 0)
		return (0);
	else if (ft_strcmp(str, "9223372036854775807") == 0)
		return (0);
	else if (ft_strcmp(str, "-9223372036854775808") > 0 && negative == 1)
		return (1);
	else if (ft_strcmp(str, "9223372036854775807") > 0)
		return (1);
	return (0);
}

int	search_on_lists(t_info *data, t_env *list, char *str)
{
	char	*signal;
	char	*content;

	signal = ft_before_set(str, '=');
	content = ft_after_set(str, '=');
	while (list)
	{
		if (ft_strcmp(signal, list->signal) == 0)
		{
			list->content = content;
			list->full_line = ft_strjoin(signal, "=");
			list->full_line = ft_strjoin(list->full_line, content);
			sub_var(data->list_env, signal, content);
			return (0);
		}
		list = list->next;
	}
	return (1);
}

void	sub_var(t_list *list, char *signal, char *content)
{
	int		len;
	char	*new_content;

	len = ft_strlen(signal) + ft_strlen(content) + 2;
	while (list)
	{
		if (ft_strcmp(ft_before_set(list->content, '='), signal) == 0)
		{
			new_content = malloc(sizeof len);
			new_content = ft_strjoin(signal, "=");
			new_content = ft_strjoin(new_content, content);
			list->content = ft_memcpy(list->content, new_content, len);
		}
		list = list->next;
	}
}
