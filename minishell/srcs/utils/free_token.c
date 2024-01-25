/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:06 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/24 19:30:46 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			free_token(void *content)
{
	t_token		*token;

	if (!content)
		return ;
	token = (t_token *)content;
	if (token && token->value)
	{
		ft_memdel(&token->value);
	}
	free(token);
	(void)token;
	(void)content;
}
