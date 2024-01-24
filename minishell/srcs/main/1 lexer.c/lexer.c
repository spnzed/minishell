/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:00:14 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/24 16:20:43 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

t_token	*create_token(void *value, t_token_type type, t_info *data)
{
	int		size;
	t_token	*token;

	size = sizeof(t_token);
	token = malloc(size);
	if (!token, !value)
		exit(free_all(&data, 1));
	token->value = value;
	token->type = type;
	return (token);
}

/*
** Clonamos el contenido de input en el valor para tratarlo
** Encontramos de que tipo es el token
** Creamos el token con el valor y el tipo
** Creamos la lista linkeada con el token
** Hacemos llst add back con el nuevo token, al list_input
*/
void	lexer(char *input, t_info	*data)
{
	char 			*value;
	t_list			*new;
	t_token			*token;
	t_token_type	type;

	value = ft_strdup(input);
	type = def_type(value[0]);
	token = create_token(value, type, &data);	//TO_DO
	new = ft_lstnew(token);
	ft_lstadd_back(&data->list_input, new);
}
