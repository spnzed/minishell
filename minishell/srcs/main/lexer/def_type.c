/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:10:36 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/24 16:10:44 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static 	t_token_type	get_type(char *str)
{
	if (str[0] == "&")
		return(and);
	if (str[0] == "|")
		return(pipeline);
	if (str[0] == "<")
		return(simple_redir_left);
	if (str[0] == ">")
		return(simple_redir_right);
	if (str[0] == ";")
		return(semicolon);
	if (str[0] == "\"")
		return(double_quote);
	if (str[0] == "'")
		return(single_quote);
	if (str[0] == "\\")
		return(backslash);
	if (str[0] == "\f" || str[0] == "\n" || str[0] == "\r" || str[0] == "\t"
			|| str[0] == "\v" || str[0] == " ")
		return(space);
	if (str[0] == "$")
		return(variable);
	if (str[0] == "\0")
		return(NULL);
}

static void		put_values(char *values, int i)
{
	if (i == 1)
		values[0] = "&";
	if (i == 2)
		values[0] = "|";
	if (i == 3)
		values[0] = "<";
	if (i == 4)
		values[0] = ">";
	if (i == 5)
		values[0] = ";";
	if (i == 6)
		values[0] = "\"";
	if (i == 7)
		values[0] = "'";
	if (i == 8)
		values[0] = "\\";
	if (i == 9)
		values[0] = "\f";
	if (i == 10)
		values[0] = "\n";
	if (i == 11)
		values[0] = "\r";
	if (i == 12)
		values[0] = "\t";
	if (i == 13)
		values[0] = "\v";
	if (i == 14)
		values[0] = " ";
	if (i == 15)
		values[0] = "$";
	if (i == 16)
		values[0] = "\0";
}

static void		get_values(char **values)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (values[i])
	{
		put_values(values[i], i);
		i++;
	}
}

/*
** type_of_token(char charset)
** This function defines the type of token for the character inside token
** the type of token depend of table => g_tab_token
*/
t_token_type		def_type(char charset)
{
	int				i;
	char			*str;
	char			**values;
	t_token_type	type;

	i = 0;
	values = malloc(sizeof(char *) * 16);
	get_values(&values);
	type = literal;
	while (values[i])
	{
		str = ft_strdup(values[i]);
		if (str[0] == charset)
		{
			type = get_type(str[0]);
				if (type == NULL)
					return (literal);
			return (type);
		}
		i++;
	}
	return (type);
}