/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:57:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/08 15:12:28 by pquintan         ###   ########.fr       */
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

//	heredoc 🤭
# define HEREDOC ".heredoc"

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
int				syntax_error(t_info *data);
t_environment	*value_export(t_environment *signals_env, char *value);
t_environment	*var_export(t_environment *signals_env, char *var);
int				var_found_env(t_environment *signals_env, char *var);
int				var_found_list(t_list *env, char *var);
t_list			*get_var_list(t_list *env, char *var);
////////////////////////////////////////////////////////////////////////////////
//				PARSER		📖
int				cmd_count(char *line);
int				**count_quotes(t_info *data);
////////////////////////////////////////////////////////////////////////////////
//				EXPANDER	🌱
char			*search_var(char *line);
int				var_found(t_environment *list_env, char *var);
char			*parse_var(t_info *data);
char			*export_id(char *var);
int				redir_syntax(char *line, t_info *data);
char			*put_variable(char *line, char *var, char *replace);
////////////////////////////////////////////////////////////////////////////////
//				EXECUTOR	🚀
char 			**add_cmd(char **route, char *cmd);
int				call_childs(t_info *data, int i);
char			*clean_redir(char *str);
int				ctrl_d(t_info *data);
char			*display_term_message(void);
void			do_builtin(t_info *data, int builtin, char **split_cmd);
//char			*display_term_message(t_info *data);
int				exec_cmds(t_info *data);
int				exec_one_cmd(t_info *data);
void			exec_process(t_info *data, char	*cmd);
int				files_in(t_info *data, t_list **in_files);
int				files_out(t_info *data);
char			*find_cmd_route(t_environment *lst_env, char *cmd);
void			get_redirections(char *cmd, t_info *data);
void			get_value_infile(t_info *data, char *cmd);
void			get_value_outfile(t_info *data, char *cmd);
void			get_value_append(t_info *data, char *cmd);
void			get_value_heredoc(t_info *data, char *cmd);
void 			remove_heredoc(void);
void			handle_heredoc(t_info *data);
int				handle_redirect(t_info *data);
int				parent_process(t_info *data);
void			prepare_to_exec(t_info *data);
void			prepare_to_exec_one(t_info *data);
char			**split_quotes(char *cmd);
//				builtins
int				is_builtin(t_info *data);
int				ft_env(t_list *list_env);
int				ft_pwd(t_info *data);
int				ft_cd(t_info *data, char **split_cmd);
int				ft_exit(t_info *data, char **split_cmd);
int				ft_echo(t_info	*data, char **line);
int				ft_export(t_info *data);
int				ft_unset(t_info *data, char **split_cmd);
int				cd_error_msg(t_info *data, char *arg, char *str);
void			set_directory(t_list *list_env, char *var);
int				cd_error_file_too_long(t_info *data, char *file);
int				permission_dir(t_info *data, char *file, char **split_cmd);

////////////////////////////////////////////////////////////////////////////////
//				UTILS		🔧
int				check_complex_cmd(char *strbase, char *strcomp, int len);
int				get_quote_final(char *line, int i, int *simple, int *complex);
void			get_quotes_type(char c, int *simple, int *complex);
int				get_redir_end(char *str, t_info *data);
int				get_redir_syntax_values(t_info *data, char c, int *simple, int *complex, int *r_left, int *r_right);
char			*normalizer(char *str);
void 			put_error(t_info *data, char *cmd, char *str, int ret);
int				reset_fd(t_info *data);
void			signal_handler_heredoc(int sig);
void			catch_signal(t_info *data, int status, int set_status);
void			signal_handler(int sig);
char			**split_cmds(t_info *data);
char			**split_pipe(char *cmd, char c);
t_list			*ft_copy_list(const t_list *src);
void			ft_free_list(t_list *head);
char			*ft_remove_quotes_str(char *str);
char			*ft_before_set(char *str, char set);
char			*ft_after_set(char *str, char set);
//				new env_utils
t_environment	*ft_envnew(void *content);
void			ft_envclear(t_environment **env, void (*del)(void*));
void			ft_envadd_back(t_environment **env, t_environment *new);
int				count_words(char *str);
void			ft_free_environment(t_environment *head);
t_environment	*ft_copy_environment(const t_environment *src);
void			set_var(t_list *head, char *id, char *value);
void			add_variable_list(t_list *head, char *value);
void			free_environment(t_environment *env);
////////////////////////////////////////////////////////////////////////////////
t_environment	*start_sig(t_list *env);
t_list			*order_env(t_list *env);

#endif