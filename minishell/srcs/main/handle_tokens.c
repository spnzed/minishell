/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:00:14 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/19 15:25:50 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

/*
** type_of_token(char charset)
** This function defines the type of token for the character inside token
** the type of token depend of table => g_tab_token
*/
static t_token_type		define_type(char charset)
{	
}

/*
** this function is a Tokenization it dividing each character in token.
** this function transforme input string in sequence of token
** This function puts each character of string input in token,
** then put this token in linked list
** Step one get one character of the input string
** step two create token with this character
** step three add this token in linked list
*/
void					tokenizer(char *input)
{
}