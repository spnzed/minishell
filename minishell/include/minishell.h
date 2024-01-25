/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:57:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/25 17:34:32 by aaespino         ###   ########.fr       */
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
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
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
#include "./srcs/utils/libft/libft.h"
#include "./include/structs.h"


//				THE PROJECT
t_list			*start_env(char **env);
//				Lexer
t_token_type	def_type(char charset);
bool			type_is_separator(t_token_type type);
void			lexer(char *input, t_info	*data);
//				Parser
int				parser(t_list *cmd, int cmd_nbr, t_info *data);
//				Executor
t_list			*next_command(int nbr, t_info *data);
void			executor(t_info	*data);
void			ctrl_c(t_info *data);
void			ctrl_d(char *buf, int r, t_info *data);
//				cleaning
int				free_all(t_info *info, int code_return);
void			free_double_array(void *ptr);
void			free_token(void *content);
void			free_tree_content(void *content);
void			free_tree(t_tree *root, void (*del)(void *));


#endif