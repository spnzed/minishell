/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:40:44 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/12 19:49:57 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
    - [ ]  put_split_quotes
        - [ ]  get_final_quote
        - [ ]  substr_split_quotes
    - [ ]  clean_split
        - [ ]  array_size
        - [ ]  size_word
        - [ ]  copy_word
*/

char **split_quotes(char *cmd)
{
	int		size;
	char	**spl;
	int		simple;
	int		complex;

	simple = 0;
	complex = 0;

	size = count_words(cmd) + 1;
	spl = malloc(sizeof(char *) * (size));
	if (!spl)
		return (NULL);
	spl[size] = NULL;
	spl = put_split_quotes(size, cmd, spl, simple, complex);
	clean_split();
	return (cmd);
}
