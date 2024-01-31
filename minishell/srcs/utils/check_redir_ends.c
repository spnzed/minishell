/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir_ends.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:36:34 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 18:53:38 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redir_ends(char *str)
{
	int	size;

	size = ft_strlen(str) - 1;
	if (str[size] == ' ')
	{
		while (str[size] == ' ')
			size--;
		if (str[size] == '<' || str[size] == '>')
		{
			return (write(2,
				"Syntax error: near unexpected token 'newline'\n",
				58));
		}
	}
	if (str[size] == '<' || str[size] == '>')
	{
		return (write(2,
			"Syntax error: near unexpected token 'newline'\n",
			58));
	}
	return (0);
}
