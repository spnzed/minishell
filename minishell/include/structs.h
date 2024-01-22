/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:07:04 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/19 15:23:11 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum		e_token_type
{
	and,					//	&&
	or,						//	||
	semicolon,				// 	;
	simple_redir_left,		//	<
	simple_redir_right,		//	>
	double_redir_left,		//	<<
	double_redir_right,		//	>>
	pipeline,				//	|
	option_command,			//	-
	single_quote,			//	'
	double_quote,			//	"
	backslash,				//	'\'
	literal,				//	
	variable,				//	
	space,					//	
}					t_token_type;

typedef struct		s_token
{
	void			*value;
	t_token_type	type;
}					t_token;


typedef struct		s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct		s_info
{
	t_list			*list_env;
	t_list			*list_input;
	t_list			*list_path;
	char			**tab_var_env;
	void			*ptr;
	int				ret;
}					t_info;

#endif