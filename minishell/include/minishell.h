/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:57:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 17:21:56 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

////////////////////////////////////////////////////////////////////////////////
//				DEFINES
////////////////////////////////////////////////////////////////////////////////
//	Colors
# define RESET   "\033[0m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define WHITE   "\033[1;37m"
//	Heredoc 🤭
# define HEREDOC "/tmp/.heredoc_"
//	libs
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <term.h>
# include <stdbool.h>
//	libft
# include "libft.h"
# include "structs.h"

////////////////////////////////////////////////////////////////////////////////
//				THE PROJECT	🥩
////////////////////////////////////////////////////////////////////////////////
int				manage_cmd(t_info *data);
void			free_info(t_info *data);
////////////////////////////////////////////////////////////////////////////////
//				LEXER		📝
////////////////////////////////////////////////////////////////////////////////
int				lexer(t_info *data, char **env);
t_environment	*start_sig(t_list *env);
t_list			*order_env(t_list *env);
int				init_env(t_info *data, char **env);
int				init_settings(t_info *data);
int				init_fd(t_info *data);
int				syntax_error(t_info *data);
t_environment	*value_export(t_environment *signals_env, char *value);
t_environment	*var_export(t_environment *signals_env, char *var);
int				var_found_env(t_environment *signals_env, char *var);
int				var_found_list(t_list *env, char *var);
t_environment	*get_var_list(t_environment *env, char *var);
char			*get_var_init(t_environment *env, char *var);
////////////////////////////////////////////////////////////////////////////////
//				PARSER		📖
////////////////////////////////////////////////////////////////////////////////
int				cmd_count(t_info *data, char *line);
char			*remove_quotes(char *str);
////////////////////////////////////////////////////////////////////////////////
//				EXPANDER	🌱
////////////////////////////////////////////////////////////////////////////////
char			*search_var(char *line);
int				comprove_var(char *line);
int				var_found(t_environment *list_env, char *var);
char			*parse_var(t_info *data);
char			*export_id(char *var);
int				redir_syntax(char *line, t_info *data);
char			*put_variable(char *line, char *var, char *replace);
////////////////////////////////////////////////////////////////////////////////
//				EXECUTOR	🚀
////////////////////////////////////////////////////////////////////////////////
char			**add_cmd(char **route, char *cmd);
int				call_childs(t_info *data, int i);
char			*clean_redir(char *str);
int				num_quotes(char *str);
char			*clean_quotes(char *str);
int				ctrl_d(t_info *data);
char			*display_term_message(t_info *data);
void			do_builtin(t_info *data, int builtin, char **split_cmd);
int				exec_cmds(t_info *data);
int				exec_one_cmd(t_info *data);
int				ft_isstrprint(char *str);
void			filter_one_cmd(t_info *data, char **splitted_cmd);
bool			comprove_redirs(t_info *data);
void			last_error(t_info *data);
void			exec_process(t_info *data, char	*cmd, int i);
void			putstr_newl_fd(char *str, int fd);
int				comprove_heredoc(t_info *data);
int				comprove_stdin(t_info *data);
int				comprove_stdout(t_info *data);
char			*find_cmd_route(t_environment *lst_env, char *cmd);
void			get_redirections(char *cmd, t_info *data);
void			get_value_heredoc(t_info *data, char *cmd);
void			get_value_infile(t_info *data, char *cmd);
void			get_value_outfile(t_info *data, char *cmd, t_type_redir code);
void			redir_add_list(char *filename, t_list **head);
int				get_next_redir(char *str, int i);
char			*get_next_filename(char *cmd);
void			remove_heredoc(void);
void			handle_heredoc_pipe(t_info *data);
int				handle_redirect(t_info *data);
int				handle_redirect_mul(t_info *data, int i);
int				parent_process(t_info *data);
int				prepare_to_exec(t_info *data);
void			prepare_to_exec_one(t_info *data);
char			**split_quotes(char *cmd);
void			open_heredocs(t_info *data);
void			write_heredoc(t_info *data, int fd, int nbr);
////////////////////////////////////////////////////////////////////////////////
//				BUILTINS	⚙️
////////////////////////////////////////////////////////////////////////////////
int				is_builtin(char **cmd, t_info *data);
int				env_builtin(t_list *list_env);
int				pwd_builtin(t_info *data);
int				cd_builtin(t_info *data, char **split_cmd);
int				exit_builtin(t_info *data, char **split_cmd);
int				echo_builtin(t_info	*data, char **line);
int				export_builtin(t_info *data, char **split_cmd);
int				unset_builtin(t_info *data, char **split_cmd);
int				cd_error_msg(t_info *data, char *arg, char *str);
void			set_directory(t_list *list_env, char *var);
int				cd_error_file_too_long(t_info *data, char *file);
int				permission_dir(t_info *data, char *file, char **split_cmd);
////////////////////////////////////////////////////////////////////////////////
//				UTILS		🔧
////////////////////////////////////////////////////////////////////////////////
t_list			*ft_copy_list(const t_list *src);
char			*ft_remove_quotes_str(char *str);
char			*ft_before_set(char *str, char set);
char			*ft_after_set(char *str, char set);
int				check_complex_cmd(char *strbase, char *strcomp);
int				get_quote_final(char *line, int i, int *simple, int *complex);
void			get_quotes_type(char c, int *simple, int *complex);
int				get_redir_end(char *str, t_info *data);
int				get_redir_syntax_values(t_info *data, char c, int *simple,
					int *complex);
char			*normalizer(char *str);
void			put_error(t_info *data, char *cmd, char *str, int ret);
void			put_error_prev(t_info *data, char *cmd, char *str, int ret);
int				reset_fd(t_info *data);
void			signal_handler_heredoc(int sig);
void			catch_signal(t_info *data, int status, int set_status);
void			signal_handler(int sig);
char			**split_cmds(t_info *data);
char			**split_pipe(t_info *data, char *cmd);
//				New env_utils
t_environment	*ft_envnew(void *content);
void			ft_envclear(t_environment **env, void (*del)(void*));
void			ft_free_environment(t_environment *head);
t_environment	*ft_copy_environment(const t_environment *src);
void			ft_envadd_back(t_environment **env, t_environment *new);
void			free_list(t_list *list);
void			free_redir_list(t_redir_list *list);
void			free_environment(t_environment *env);
void			free_array(char **array);
int				count_words(char *str);
void			set_var(t_list *head, char *id, char *value);
void			add_variable_list(t_list *head, char *value);
// 				New export_utils
int				ft_is_bigger_maxll(char *str);
void			ft_normin(char **split_cmd);
int				ft_environmentsize(t_environment *env);
int				ft_envsize(t_environment *lst);
char			**ft_env_to_array(t_environment *head);
t_environment	*loop_exp(int index, int len, t_environment *exp_order);
t_environment	*order_exp(t_environment *exp);
void			sub_var(t_list *list, char *signal, char *content);
int				search_on_lists(t_info *data, t_environment *list, char *str);
int				search_list_else(t_environment *list, char *signal);
void			add_array(int strsize, t_environment *temp, char *array);
void			export_error_not_valid_id(char *arg, t_info *data);
char			*first_num(char *var);
int				export_valid(char *cmd);
int				cmdsize(char **command);
void			part_one(char **line, t_echo *e);
void			loop_one(char **line, t_echo *e, t_info *data);
void			list_exp_add(char *cmd, t_info *data);
void			export_and_grep(t_environment *temp, char **split_cmd, int x);

#endif