/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_substr_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:04:39 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/22 20:32:07 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*split_substr_quotes(char *cmd, int first_quote, int final_quote, int count)
{
	int		len;
	char 	*ret_line;

	len = ft_strlen(cmd);
	if (count == 0)
		ret_line = ft_substr(cmd, first_quote, final_quote - first_quote);
	else if ((final_quote + 1) < len)
		ret_line = ft_substr(cmd, first_quote + 1, final_quote - 1);
	else
		ret_line = ft_substr(cmd, first_quote, final_quote - first_quote);
	return (ret_line);
}
