################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		=	minishell
RM			=	rm -f
CC			=	gcc
FLAGS		=	-g -Wall -Wextra -Werror -I./include/
LIBFT		=	libft/libft.a

# Flags for Patri READLINE
#LDFLAGS = /System/Volumes/Data/sgoinfre/Perso/pquintan/homebrew/opt/readline/lib
#RFLAGS = /System/Volumes/Data/sgoinfre/Perso/pquintan/homebrew/opt/readline/include

################################################################################
#                                  COLOR CONFIG                                #
################################################################################

CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m

################################################################################
#                             PROGRAM'S DIR + FILES                            #
################################################################################

PROGRAM_DIR		=	srcs/main
UTILS_DIR		=	srcs/utils/
INC_DIR			=	include/
EXECUTOR_DIR	=	srcs/main/executor
LEXER_DIR		=	srcs/main/lexer
PARSER_DIR		=	srcs/main/parser

LIBFT_DIR		= 	libft/

PROGRAM_SRCS	=	minishell.c \

UTILS_SRCS		=	free_all.c \
					free_double_array.c \
					free_token.c \
					free_tree_content.c \
					free_tree.c \

EXECUTOR_SRCS	=	ctrl_d.c \
					display.c \
					executor.c \
					signal_handler.c \

LEXER_SRCS		=	def_type.c \
					handle_type.c \
					lexer.c \

PARSER_SRCS		=	parser.c \

INC_SRCS		=	minishell.h \
					structs.h \

OBJS			=	$(SRCS:.c=.o)
DEPS    	    = 	$(SRCS:.c=.d)

.c.o	:
	${CC} ${FLAGS} -MMD -c $< -o $@

################################################################################
#                                  Makefile  objs                              #
################################################################################



$(NAME)	:	$(LIBFT) $(OBJ) Makefile include/minishell.h
		make -C ./utils/libft
		@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
		$(CC) -L$(LDFLAGS) -o $(NAME) $(OBJ) -L./utils/libft -lft 
		@echo "$(GREEN)$(NAME) created ✔️"

all		:	$(NAME)

clean	:
		make clean -C ./utils/libft
		rm -f $(NAME) $(OBJ)
		@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
		@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)deps ✔️"

fclean	:	clean
		make fclean -C ./utils/libft
		$(RM) $(NAME)
		@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re		:	fclean all

-include ${DEPS}

.PHONY:		all clean fclean re
