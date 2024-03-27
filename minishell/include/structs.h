/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:35:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/27 15:17:50 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//	ENUMS

typedef enum e_token_type
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

typedef enum e_cmd_type
{
	ECHO_,
	CD_,
	PWD_,
	EXPORT_,
	UNSET_,
	ENV_,
	EXIT_,
}					t_cmd_type;

typedef enum e_type_redir
{
	SIMPLE_INFILE,
	HEREDOC_INFILE,
	SIMPLE_OUTFILE,
	APPEND_OUTFILE,
}					t_type_redir;

//	STRUCTS

//	Token
typedef struct s_environment
{
	char					*full_line;
	char					*signal;
	char					*content;
	struct s_environment	*next;
}					t_environment;

//	Data
typedef struct s_info
{
	int				cmd_nbr;
	int				exit_id;
	int				last_fd;
	int				fd[2];
	int				is_builtin;
	int				ret;
	int				std_in;
	int				std_out;
	int				**index_quotes;

	void			*ptr;

	char			*cmd_line;
	char			*cmd_clean;
	char			*home;
	char			*str_trim;
	char			*root_path;
	char			*found;
	char			**env;
	char			**one_cmd;
	char			**mul_cmds;
	char			**split_line;
	char			**cmd_split;
	char			**tab_var_env;

	t_list			*list_env;
	t_list			*list_input;
	t_list			*list_path;

	t_list			*list_in_files;
	t_list			*list_out_files;
	// t_list			*list_out_append;
	t_list			*list_heredocs;

	t_environment	*signals_env;
	t_environment	*list_exp;

	char			*string_infile;
	char			*string_outfile;
	char			*string_overwrite;
	char			*string_heredoc;
	char			*string_append;
	char			*from_file;

	bool			is_infile;
	bool			is_outfile;
	bool			is_heredoc;
	bool			is_append;

	pid_t			pid;

	struct termios	n_settings;
	struct termios	o_settings;
}					t_info;

typedef struct s_token
{
	void			*value;
	t_token_type	type;
}					t_token;
//	Command Tree
typedef struct s_tree
{
	void			*content;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

typedef struct s_var
{
	int			len_var;
	int			len_before_var;
	int			len_after_var;
	int			final_position;
	char		*str_before_var;
	char		*str_after_var;
}				t_var;

#endif