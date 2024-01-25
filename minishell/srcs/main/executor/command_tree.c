/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:57:18 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/24 19:30:20 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

t_list	*next_command(int nbr, t_info *data)
{
	int		count;
	t_list	*tmp;
	t_token	*token;

	count = 0;
	tmp	= data->list_input;
	while (nbr && tmp)
	{
		token = tmp->content;
		if (type_is_separator(token->type))
			count++;
		if (count == nbr)	
			return (tmp->next);
		tmp = tmp->next;
	}
	return (data->list_input);
}

/*DOESNT WORK

	To build:
	- parser
	- build_ast??????????????
	- clear_tree
*/

void	command_tree(t_info	*data)
{
	int		cmd_nbr;
	t_tree	*root;
	t_list	*cmd;

	cmd_nbr = 0;
	cmd = next_command(cmd_nbr, &data);
	while (cmd)
	{
		root = 0;
		if (parser(cmd, cmd_nbr))
			return ;
		cmd = next_command(cmd_nbr, &data);
		build_ast(&root, &cmd);
		data->ptr = root;
		clear_tree(root, &free_tree_content);
		if (handle_separator(&cmd, data->ret))
			return ;
		cmd_nbr++;	
	}
}