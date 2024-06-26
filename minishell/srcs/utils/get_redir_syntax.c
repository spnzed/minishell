/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:25:13 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/29 20:11:45 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redir_syntax_values(t_info *data, char c, int *simple, int *complex)
{
	int	r_left;
	int	r_right;

	r_left = 0;
	r_right = 0;
	if (c == '<' && !*complex && !*simple)
		r_left += 1;
	else if (c == '>' && !*complex && !*simple)
		r_right += 1;
	if (ft_isprint(c) && !*complex && !*simple)
	{
		r_left = 0;
		r_right = 0;
	}
	if (r_left > 2 && r_right == 0)
	{
		data->exit_id = 2;
		return (write(2, "minishell: line 1: syntax error \
			near unexpected token `newline'\n", 65), 2);
	}
	else if (r_right > 2 && r_left == 0)
	{
		data->exit_id = 2;
		return (write(2, "minishell: line 1: syntax error \
			near unexpected token `>'\n", 59), 2);
	}
	return (0);
}
