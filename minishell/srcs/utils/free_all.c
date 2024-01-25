/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:15:38 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/25 13:38:53 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_all(t_info *info, int code)
{
	ft_lstclear(&info->list_input, &free_token);
	info->list_input = 0;
	if (code == 1)
	{
		ft_lstclear(&info->list_env, &ft_free_string);
		info->list_env = 0;
	}
	ft_lstclear(&info->list_path, ft_free_string);
	info->list_path = 0;
	free(info->tab_var_env);
	info->tab_var_env = 0;
	return (info->ret);
}
