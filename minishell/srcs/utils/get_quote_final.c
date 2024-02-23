/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:26:52 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/23 13:34:48 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_quote_final(char *line, int i, int *simple, int *complex)
{
	while (((ft_isprint(line[i]) && line[i] != ' ' && 
		(!*simple && !*complex))) || (ft_isprint(line[i]) && (*simple || *complex)))
	{
		// if ((*simple || *complex) && (line[i] == '\'' || line[i] == '\'')
		// 	&& !ft_isspace(line[i + 1]))
		// 	return (i);
		get_quotes_type(line[i], simple, complex);
		i++;
	}
	return (i);
}

// int	get_quote_final(char *line, int i, int *simple, int *complex)
// {
// 	bool	we_in_quotes;

// 	we_in_quotes = false;
// 	if (line[i] != '\'' || line[i] != '\"')
// 	{
// 		while (line[i])
// 		{
// 			if (line[i] == '\'' || line[i] == '\"')
// 			{
// 				if (we_in_quotes == true)
// 					we_in_quotes = false;
// 				else
// 					we_in_quotes = true;
// 			}
// 			if (ft_isprint(line[i]) && ft_isprint(line[i + 1])
// 				&& (((line[i + 1] == '\'' || line[i + 1] == '\"') 
// 				&& we_in_quotes == true)))
// 				return (i - 1);
// 			i++;
// 		}
// 		if (line[i - 1] == '\'' || line[i] == '\"')
// 			return (i - 1);
// 		return (i);
// 	}
// 	else
// 	{
// 		while (line[i])
// 		{
// 			if (line[i] == '\'' || line[i] == '\"')
// 			{
// 				if (we_in_quotes == true)
// 					we_in_quotes = false;
// 				else
// 					we_in_quotes = true;
// 			}
// 			if (ft_isprint(line[i]) && ft_isprint(line[i + 1])
// 				&& (((line[i + 1] == '\'' || line[i + 1] == '\"') 
// 				&& we_in_quotes == true)))
// 				return (i);
// 			i++;
// 		}
// 		if (line[i] == '\'' || line[i] == '\"')
// 			return (i);
// 		return (i);
// 	}
// }
