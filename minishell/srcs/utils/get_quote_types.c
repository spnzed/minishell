/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:20:56 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 18:21:12 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_quotes_type(char c, int *simple, int *complex)
{
	if (c == '\'')
		*simple += 1;
	if (c == '\"')
		*complex += 1;
	if (c == '\'' && *simple == 2)
		*simple = 0;
	if (c == '\"' && *complex == 2)
		*complex = 0;
}
