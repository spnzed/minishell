/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:11:02 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/24 18:12:52 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

bool	type_is_separator (t_token_type type)
{
	if (type == and || type == or || type == semicolon)
		return (true);
	return (false);
}