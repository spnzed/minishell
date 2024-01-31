/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:57:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 18:32:02 by pquintan         ###   ########.fr       */
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

//				INIT PROGRAM
int				init_data(t_info *data, char **env);
int				init_env(t_info *data, char **env);
int				init_settings(t_info *data);
int				init_fd(t_info *data);


///////////////////////////////////////////////////////////////////////////////////////////
//				Lexer
t_token_type	def_type(char charset);
bool			type_is_separator(t_token_type type);
void			lexer(char *input, t_info	*data);
//				Parser
int				parser(t_list *cmd, int cmd_nbr, t_info *data);
//				manage_commands
t_list			*next_command(int nbr, t_info *data);
void			manage_commands(t_info	*data);
void			signal_handler(int sig);
int				ctrl_d(t_info *data);
//				cleaning
int				free_all(t_info *info, int code_return);
void			free_double_array(void *ptr);
void			free_token(void *content);
void			free_tree_content(void *content);
void			free_tree(t_tree *root, void (*del)(void *));
void			free_env(t_list *env);
char			**free_array(char **Array, int len);
int				array_size(char **Array);

//				Display
char			*display_term_message(void);

#endif