/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:12:51 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 15:24:06 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int handle_quotes(t_list **list)
// {
	
// }

// int	check_quotes(t_list **list)
// {
// 	t_token	*token;

// 	(void)list;
// 	if (list)
// 	{
// 		while (*list)
// 		{
// 			token = ((*list))->content;
// 			if (token->type == single_quote || token->type == double_quote)
// 				if (handle_quotes(list))
// 					return (1);
// 			*list = (*list)->next;
// 		}
// 	}
// 	return (0);
// }

int	parser(t_list *cmd, int cmd_nbr, t_info *data)
{
	// if ((check_quotes(&cmd)))
	// 	return (1);
	// cmd = next_command(cmd_nbr, &data);
	// if ((iter_list_2(cmd)))
	// 	return (1);
	// cmd = next_command(cmd_nbr, &data);
	// if (iter_list_3(cmd))
	// 	return (1);
	(void)cmd;
	(void)cmd_nbr;
	(void)data;
	return (0);
}