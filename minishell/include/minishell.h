/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:57:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/07 16:09:07 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//	colors
# define RESET   "\033[0m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define WHITE   "\033[1;37m"

//	libs
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <termios.h>
#include <term.h>
#include <stdbool.h>

//	libft
#include "libft.h"
#include "structs.h"


//				THE PROJECT

//				Lexer
int				lexer(t_info *data, char **env);
int				init_env(t_info *data, char **env);
int				init_settings(t_info *data);
int				init_fd(t_info *data);
void			signal_handler(int sig);
t_token_type	def_type(char charset);
int				type_is_separator(t_token_type type);
void			not_interactive_lexer(char *input, t_info *data);
int				syntax_error(t_info *data);

//				Parser
char			*parse_var(t_info *data);
int				var_is_found(t_environment *list_env, char *var);
char			*put_status(t_info *data, char *var);
char			*put_variable(char *line, char *var, char *replace);

//				Executor
int				ctrl_d(t_info *data);
int				exec_cmds(t_info *data);


//				Expander

//				builtins
void			ft_env(t_list **list_env);
void			ft_pwd(void);
void			ft_cd(void);
void			ft_echo(char *line, int len);
void			ft_builtins(t_info *data);
void			ft_builtins(t_info *data);

//				manage_command
void			ft_builtins(t_info *data);
int				manage_cmd(t_info *data);
int				counter_cmd(char *line);

//				display
char			*display_term_message(void);

//				cleaning
int				free_all(t_info *info, int code_return);
void			free_double_array(void *ptr);
void			free_token(void *content);
void			free_tree_content(void *content);
void			free_tree(t_tree *root, void (*del)(void *));
void			free_env(t_list *env);
char			**free_array(char **Array, int len);
int				array_size(char **Array);

//				general_utils
void			get_quotes_type(char c, int *simple, int *complex);
int				get_redir_syntax_values(char c, int *simple, int *complex, int *r_left, int *r_right);
int				check_redir_ends(char *str);
int				ft_check_complex_cmd(char *strbase, char *strcomp, int len);
char 			*ft_normal(char *str);

//				search_var
char			*search_var(char *line);
int				check_var_syntax(char *var);
char			*export_id(char *var);
char			*parse_var(t_info *data);


t_environment	*ft_envnew(void *content);
void			ft_envclear(t_environment **env, void (*del)(void*));
void			ft_envadd_back(t_environment **env, t_environment *new);



#endif