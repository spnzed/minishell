/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:12:51 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/25 14:20:41 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"



int	parser(t_list *cmd, int cmd_nbr, t_info *data)
{
	if ((iter_list_1(&cmd)))
		return (1);
	cmd = next_command(cmd_nbr, &data);
	if ((iter_list_2(cmd)))
		return (1);
	cmd = next_command(cmd_nbr, &data);
	if (iter_list_3(cmd))
		return (1);
	return (0);
}