/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:07:04 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/24 17:58:29 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//	STRUCTS

//	Our data
typedef struct		s_info
{
	t_list			*list_env;
	t_list			*list_input;
	t_list			*list_path;
	char			**tab_var_env;
	void			*ptr;
	int				ret;
}					t_info;
//	Token
typedef struct		s_token
{
	void			*value;
	t_token_type	type;
}					t_token;
//	Command Tree
typedef struct		s_tree
{
	void			*content;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_tree;

//	ENUMS

typedef enum		e_token_type
{
	and,					//	'&&'
	or,						//	'||'
	semicolon,				// 	';'
	simple_redir_left,		//	'<'
	simple_redir_right,		//	'>'
	double_redir_left,		//	'<<'
	double_redir_right,		//	'>>'
	pipeline,				//	'|'
	option_command,			//	'-'
	single_quote,			//	'''
	double_quote,			//	'"'
	backslash,				//	'\'
	variable,				//	'$'
	space,					//	'\f', '\n', '\r', '\t', '\v', ' '
	literal,				//	
}					t_token_type;


#endif