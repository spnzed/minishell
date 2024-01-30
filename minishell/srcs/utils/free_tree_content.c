/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:26:16 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/30 14:41:14 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tree_content(void *content)
{
	t_token	*token;

	if (!content)
		return ;
	token = (t_token *) content;
	free_double_array(token->value);
	free(token);
	(void)token;
	(void)content;
}