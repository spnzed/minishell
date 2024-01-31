/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:07:04 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 18:32:34 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

//	STRUCTS
//	Our data
typedef struct		s_info
{
	t_list			*list_env;
	t_list			*list_input;
	t_list			*list_path;

	struct termios	o_settings;
	struct termios	n_settings;

	int				std_in;
	int				std_out;
	int				status;

	char			**env;

	char			**tab_var_env;
	void			*ptr;
	int				ret;
	char			*cmd_line;
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
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;


#endif