/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:57:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/15 17:11:11 by pquintan         ###   ########.fr       */
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
int				manage_cmd(t_info *data);
////////////////////////////////////////////////////////////////////////////////
//				LEXER		📝
int				lexer(t_info *data, char **env);
//				non_interactive
void			not_interactive_lexer(char *input, t_info *data);
t_token_type	def_type(char charset);
//				interactive
int				init_env(t_info *data, char **env);
int				init_settings(t_info *data);
int				init_fd(t_info *data);
////////////////////////////////////////////////////////////////////////////////
//				PARSER		📖
int				cmd_count(char *line);
int				syntax_error(t_info *data);
////////////////////////////////////////////////////////////////////////////////
//				EXPANDER	🌱
char			*search_var(char *line);
char			*parse_var(t_info *data);
char			*export_id(char *var);
int				redir_syntax(char *line);
char			*put_variable(char *line, char *var, char *replace);
////////////////////////////////////////////////////////////////////////////////
//				EXECUTOR	🚀
char			*clean_redir(char *str);
int				ctrl_d(t_info *data);
char			*display_term_message(void);
int				exec_cmds(t_info *data);
void			exec_process(t_info *data, char	*cmd);
void			signal_handler(int sig);
//				builtins
void			ft_builtins(t_info *data);
void			ft_env(t_list **list_env);
void			ft_pwd(void);
void			ft_cd(t_info *data);
void			ft_exit(t_info *data);
void			ft_echo(char *line, int len);
void			ft_export(t_info *data);
////////////////////////////////////////////////////////////////////////////////
//				UTILS		🔧
int				check_complex_cmd(char *strbase, char *strcomp, int len);
void			error_exit(t_info *data);
void			get_quotes_type(char c, int *simple, int *complex);
int				get_redir_end(char *str);
int				get_redir_syntax_values(char c, int *simple, int *complex, int *r_left, int *r_right);
char			*normalizer(char *str);
t_list			*ft_copy_list(const t_list *src);
void			ft_free_list(t_list *head);
char			*ft_remove_quotes_str(char *str);
char			*ft_before_set(char *str, char set);
char			*ft_after_set(char *str, char set);
//				new env_utils
t_environment	*ft_envnew(void *content);
void			ft_envclear(t_environment **env, void (*del)(void*));
void			ft_envadd_back(t_environment **env, t_environment *new);
////////////////////////////////////////////////////////////////////////////////
t_environment	*start_sig(t_list *env);
t_list			*order_env(t_list *env);

#endif