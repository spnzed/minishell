/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:26:52 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/14 18:10:38 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_quote_final(char *str, int i, int simple, int complex)
{
	i--;
	while ((ft_isprint(str[++i] && str[i] != ' ' && (!simple && !complex)))
			|| (ft_isprint(str[i]) && (simple || complex)))
		get_quotes_type(str[i], &simple, &complex);
	return (i);
}