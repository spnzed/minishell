################################################################################
#                                     CONFIG                                   #
################################################################################´

NAME		=	minishell

CC			=	gcc
RLFLAGS     =   -lreadline
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
CLEAN_CAR	=	\033[2K\r

AR			=	ar rcs
RM			=	rm -f
MD			=	mkdir -p
CP			=	cp -f

################################################################################
#                             PROGRAM'S DIR + FILES                            #
################################################################################

#aaespino flags
RFLAGS = /Users/aaespino/.brew/opt/readline/include
LDFLAGS = /Users/aaespino/.brew/opt/readline/lib

#pquintan flags
#RFLAGS = /sgoinfre/Perso/pquintan/homebrew/opt/readline/include
#LDFLAGS = /sgoinfre/Perso/pquintan/homebrew/opt/readline/lib

SRCS_DIR		=	srcs/
OBJ_DIR			=	obj/

MAIN_DIR		=	main/
UTILS_DIR		=	utils/
INC_DIR			=	include/
EXECUTOR_DIR	=	executor/
LEXER_DIR		=	lexer/
PARSER_DIR		=	parser/
INIT_DIR		=	init/
MANAGE_CMD_DIR	=	manage_cmd/
BUILTINS_DIR	=	builtins/

OBJ_DIR			=	build/

INC_DIR			=	include/
LIBFT_INC		= 	libft/

LIBFT_DIR		= 	libft/
LIBFT			=	libft/libft.a

INCLUDE			+= -I $(INC_DIR) -I $(LIBFT_INC)

MINISHELL		=	minishell.c

MAIN			=	manage_cmd.c

BUILTINS		=	cd.c \
					cd_utils.c \
					cd_utils2.c \
					echo.c \
					echo_utils.c \
					env.c \
					exit.c \
					exit_utils.c \
					export.c \
					export_utils.c \
					export_utils2.c \
					is_builtin.c \
					pwd.c \
					unset.c

LEXER			=	init_data.c \
					init_env.c \
					init_env_utils.c \
					init_fd.c \
					init_settings.c \
					lexer_utils.c \
					search_var.c \
					syntax_error.c \
					utils_var.c \
					utils_var2.c

PARSER 			=	parse_var.c \
					put_variable.c \
					remove_quotes.c

EXECUTOR		=	add_cmd.c \
					call_childs.c \
					clean_quotes.c \
					clean_redir.c \
					ctrl_d.c \
					display_term_message.c \
					exec_cmds.c \
					exec_one_cmd.c \
					exec_one_utils.c \
					exec_process.c \
					files_in.c \
					files_out.c \
					find_cmd_route.c \
					get_redirections.c \
					get_values.c \
					get_values_utils.c \
					handle_heredoc.c \
					handle_redirect.c \
					parent_process.c \
					prepare_to_exec.c \
					split_quotes.c

UTILS		 	=	check_complex_cmd.c \
					cmd_count.c \
					copy_environment.c \
					copy_list.c \
					count_words.c \
					free.c \
					get_quote_final.c \
					get_quote_types.c \
					get_redir_end.c \
					get_redir_syntax.c \
					normalizer.c \
					remove_quotes_str.c \
					setters.c \
					put_error.c \
					reset_fd.c \
					signal_handler.c \
					split_cmds.c \
					split_pipe.c \
					utils_env.c \
					var_set.c \
					cmd_size.c

SRCS			+=	$(addprefix $(SRCS_DIR), $(MINISHELL))
SRCS			+= 	$(addprefix $(SRCS_DIR), $(addprefix $(MAIN_DIR), $(MAIN)))
SRCS			+= 	$(addprefix $(SRCS_DIR), $(addprefix $(EXECUTOR_DIR), $(EXECUTOR)))
SRCS			+= 	$(addprefix $(SRCS_DIR), $(addprefix $(LEXER_DIR), $(LEXER)))
SRCS			+= 	$(addprefix $(SRCS_DIR), $(addprefix $(PARSER_DIR), $(PARSER)))
SRCS			+= 	$(addprefix $(SRCS_DIR), $(addprefix $(UTILS_DIR), $(UTILS)))
SRCS			+= 	$(addprefix $(SRCS_DIR), $(addprefix $(INIT_DIR), $(INIT)))
SRCS			+= 	$(addprefix $(SRCS_DIR), $(addprefix $(MANAGE_CMD_DIR), $(MANAGE_CMD)))
SRCS			+= 	$(addprefix $(SRCS_DIR), $(addprefix $(BUILTINS_DIR), $(BUILTINS)))

OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS			+=	$(addsuffix .d, $(basename $(OBJS)))


################################################################################
#                                     MAKEFILE                                 #
################################################################################

$(OBJ_DIR)%.o : %.c Makefile 
	@$(MD) $(dir $@)
	@make -sC $(LIBFT_DIR)
	@printf "$(CLEAN_CAR)$(OK_COLOR)[minishell Compiling]$(BLUE_COLOR) : $(WARN_COLOR)$<$(NO_COLOR)"

	@$(CC) -MT $@ -MMD -MP -c $(CFLAGS) -I$(RFLAGS) -Iinclude/ $(INCLUDE) $< -o $@

all:		libft_link $(NAME) 

$(NAME):	$(LIBFT) $(OBJS) 
			@$(CC) $(CFLAGS) $(RLFLAGS) -L $(LDFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
			@sleep 0.2
			@echo "$(CLEAN_CAR)$(OK_COLOR)Minishell Compiled!$(NO_COLOR)"
			@echo "Use $(BLUE_COLOR)./minishell$(NO_COLOR) to launch the program"

clean:
			@make clean -sC $(LIBFT_DIR)
			@$(RM) -r $(OBJ_DIR)
			@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"

fclean:		
			@make fclean -sC $(LIBFT_DIR)
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(NAME)
			@echo "$(ERROR_COLOR)$(NAME) removed$(NO_COLOR)"

re:			fclean all

run:		all
			@echo ""
			@echo "$(OK_COLOR)Launching Minishell...$(NO_COLOR)"
			@echo ""
			@valgrind --leak-check=full ./minishell

leak:		all
			@echo ""
			@echo "$(OK_COLOR)Launching Minishell...$(NO_COLOR)"
			@echo ""
			@leaks -atExit -- ./minishell

libft_link:	
			@make -sC $(LIBFT_DIR)

-include $(DEPS)

.PHONY: all clean fclean re run leak libft_link

################################################################################
#                                    COLOR                                     #
################################################################################

NO_COLOR		=	\x1b[0m
OK_COLOR		=	\x1b[32;01m
ERROR_COLOR		=	\x1b[31;01m
WARN_COLOR		=	\x1b[33;01m
BLUE_COLOR		=	\x1b[34;01m

OK_STRING		=	$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING	=	$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING		=	$(WARN_COLOR)[WARNINGS]$(NO_COLOR)
