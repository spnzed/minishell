################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		=	minishell
RM			=	rm -f
CC			=	gcc
FLAGS		=	-g -Wall -Wextra -Werror -I./include/ -I$(LIBFT_DIR)
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

SRCS_DIR		=	srcs/
OBJ_DIR			=	obj/
MAIN_DIR		=	srcs/main
UTILS_DIR		=	srcs/utils/
INC_DIR			=	include/
EXECUTOR_DIR	=	srcs/main/executor
LEXER_DIR		=	srcs/main/lexer
PARSER_DIR		=	srcs/main/parser

LIBFT_DIR		= 	libft/

MAIN_SRCS		=	minishell.c \

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

SRCS			:=	$(addprefix $(SRCS), $(addprefix $(MAIN_DIR), $(MAIN_SRCS)))
SRCS			+=	$(addprefix $(SRCS), $(addprefix $(UTILS_DIR), $(UTILS_SRCS)))
SRCS			+=	$(addprefix $(SRCS), $(addprefix $(EXECUTOR_DIR), $(EXECUTOR_SRCS)))
SRCS			+=	$(addprefix $(SRCS), $(addprefix $(LEXER_DIR), $(LEXER_SRCS)))
SRCS			+=	$(addprefix $(SRCS), $(addprefix $(PARSER_DIR), $(PARSER_SRCS)))


################################################################################
#                                  Makefile  objs                              #
################################################################################


OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS			+=	$(addsuffix .d, $(basename $(OBJS)))

.c.o:
	$(CC) $(FLAGS) -MMD -c $< -o $@

all		:	libft_link $(NAME)

$(NAME)	:	$(LIBFT) $(OBJ) Makefile include/minishell.h
		@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
		@$(CC) -L$(LDFLAGS) $(OBJ) ${LIBFT_DIR} -lft -o $(NAME)
		@echo "$(GREEN)$(NAME) created ✔️"

clean	:
		@make clean -C ${LIBFT_DIR}
		rm -f $(NAME) $(OBJ)
		@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
		@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)deps ✔️"

fclean	:	clean
		@make fclean -C ${LIBFT_DIR}
		@$(RM) $(NAME)
		@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re		:	fclean all

libft_link:	
			@make -sC $(LIBFT_DIR)

-include ${DEPS}

.PHONY:		all clean fclean re libft_link
