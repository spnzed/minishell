/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_interactive_lexer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:00:14 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/09 15:30:02 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(void *value, t_token_type type, t_info *data)
{
	t_token	*token;

	(void)data;
	token = malloc(sizeof(t_token));
	if (!token || !value)
		exit(1);
	token->value = value;
	token->type = type;
	return (token);
}

void	not_interactive_lexer(char *input, t_info *data)
{
	char 			*value;
	t_list			*new;
	t_token			*token;
	t_token_type	type;

	value = ft_strdup(input);
	type = def_type(value[0]);
	token = create_token(value, type, data);
	new = ft_lstnew(token);
	ft_lstadd_back(&data->list_input, new);
}
