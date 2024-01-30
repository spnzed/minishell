################################################################################
#                                     CONFIG                                   #
################################################################################´

NAME		=	minishell

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
CLEAN_CAR	=	\033[2K\r

AR			=	ar rcs
RM			=	rm -f
MD			=	mkdir -p
CP			=	cp -f

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

OBJ_DIR			=	build/

INC_DIR			=	include/
LIBFT_INC		= 	libft/

LIBFT_DIR		= 	libft/
LIBFT			=	libft/libft.a

INCLUDE			+= -I $(INC_DIR) -I $(LIBFT_INC)


MAIN			=	minishell.c
UTILS		 	=	free_all.c free_double_array.c free_token.c free_tree_content.c free_tree.c 
EXECUTOR		=	ctrl_d.c display.c executor.c signal_handler.c 
LEXER			=	def_type.c handle_type.c lexer.c 
PARSER 			=	parser.c

SRCS			+=	$(addprefix $(SRCS_DIR), $(MAIN))
SRCS			+= 	$(addprefix $(SRCS_DIR), $(addprefix $(EXECUTOR_DIR), $(EXECUTOR)))
SRCS			+= 	$(addprefix $(SRCS_DIR), $(addprefix $(LEXER_DIR), $(LEXER)))
SRCS			+= 	$(addprefix $(SRCS_DIR), $(addprefix $(PARSER_DIR), $(PARSER)))
SRCS			+= 	$(addprefix $(SRCS_DIR), $(addprefix $(UTILS_DIR), $(UTILS)))

OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS			+=	$(addsuffix .d, $(basename $(OBJS)))


################################################################################
#                                     MAKEFILE                                 #
################################################################################

$(OBJ_DIR)%.o : %.c Makefile 
	@$(MD) $(dir $@)
	@make -sC $(LIBFT_DIR)
	@printf "$(CLEAN_CAR)$(OK_COLOR)[minishell Compiling]$(BLUE_COLOR) : $(WARN_COLOR)$<$(NO_COLOR)"
	
	@$(CC) -MT $@ -MMD -MP -c $(CFLAGS) -I$(RFLAGS) $(INCLUDE) $< -o $@ 


all:		libft_link $(NAME) 

$(NAME):	$(LIBFT) $(OBJS) 
			@$(CC) $(CFLAGS) -L $(LIBFT) $(OBJS) -o $(NAME)
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
			@./minishell

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
