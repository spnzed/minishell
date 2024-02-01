/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:25:13 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 19:00:26 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Revisar ultimo if
int	get_redir_syntax_values(char c, int *simple, int *complex, int *r_left,
	 int *r_right)
{
	if (c == '<' && !*complex && !*simple)
		*r_left += 1;
	else if (c == '>' && !*complex && !*simple)
		*r_right += 1;
	if (ft_isspace(c) && !*complex && !*simple)
	{
		*r_left = 0;
		*r_right = 0;
	}
	if (((*r_left > 2 && *r_right == 0) || (*r_right > 2 && *r_left == 0))
		|| (*r_left && *r_right))
		return (write(2, "Syntax error: Near unexpected token `>'\n", 52));
	return (0);
}
