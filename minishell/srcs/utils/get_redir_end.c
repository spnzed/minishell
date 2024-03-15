/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:36:34 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 18:53:38 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redir_end(char *str, t_info *data)
{
	int	size;

	size = ft_strlen(str) - 1;
	if (str[size] == ' ')
	{
		while (str[size] == ' ')
			size--;
		if (str[size] == '<' || str[size] == '>')
		{
			put_error_prev(data, 0, "syntax error near unexpected token `newline'\n", 
				2);
		}
	}
	if (str[size] == '<' || str[size] == '>')
	{
		put_error_prev(data, 0, "syntax error near unexpected token `newline'\n", 
			2);
	}
	return (0);
}
