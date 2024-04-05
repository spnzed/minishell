/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:35:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/05 18:30:57 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

////////////////////////////////////////////////////////////////////////////////
//	TYPEDEFS
////////////////////////////////////////////////////////////////////////////////

typedef enum e_type_redir
{
	SIMPLE_INFILE,
	HEREDOC_INFILE,
	SIMPLE_OUTFILE,
	APPEND_OUTFILE,
}					t_type_redir;

////////////////////////////////////////////////////////////////////////////////
//	STRUCTS
////////////////////////////////////////////////////////////////////////////////

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
	void			*ptr;

	int				cmd_nbr;
	int				exit_id;
	int				last_fd;
	int				is_builtin;
	int				ret;
	int				std_in;
	int				std_out;
	int				count;
	int				start;
	int				fd[2];
	int				**index_quotes;

	bool			is_infile;
	bool			is_outfile;
	bool			is_heredoc;
	bool			is_append;

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
	char			**HEREDOC_keys;

	char			*string_infile;
	char			*string_outfile;
	char			*string_overwrite;
	char			*string_heredoc;
	char			*string_append;
	char			*from_file;

	pid_t			pid;

	t_list			*list_env;
	t_list			*list_input;
	t_list			*list_path;

	t_list			*list_in_files;
	t_list			*list_out_files;
	t_list			*list_heredocs;

	t_environment	*signals_env;
	t_environment	*list_exp;

	struct termios	n_settings;
	struct termios	o_settings;
}					t_info;

typedef struct s_echo
{
	int		i;
	int		j;
	int		n;
	int		len;
	char	quote;
	bool	n_option;
}			t_echo;

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