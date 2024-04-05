NAME		=	libft.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
OBJ_DIR		=	build/
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(OBJ_DIR)/$*.d

MD			=	mkdir -p

SRC			=	ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isspace.c \
				ft_isprint.c \
				ft_memset.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_strlcat.c \
				ft_bzero.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_calloc.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_itoa.c \
				ft_split.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstpos.c \
				ft_cleanp.c \
				ft_strndup.c \
				ft_free_string.c \
				ft_memdel.c \
				ft_strpbrk.c \
				ft_strjoin_clean.c \
				ft_strcmp.c \
				ft_first_word.c \
				ft_arrlen.c \
				ft_arrfree.c \
				ft_findalnum.c \
				ft_atoll.c \
				ft_isnumeric.c \
				ft_strcmp_len.c \

OBJECTS		= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEPS		= $(addsuffix .d, $(basename $(OBJS)))

$(OBJ_DIR)%.o : %.c Makefile
	@$(MD) $(dir $@)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@echo "$(OK_COLOR)Libft done!$(NO_COLOR)"

all: $(NAME)

clean:
	@rm -f -r $(OBJ_DIR)
	@echo "$(BLUE_COLOR)clean libft done!$(NO_COLOR)"

fclean:
	@rm -f -r $(OBJ_DIR)
	@rm -f $(NAME)
	@echo "$(BLUE_COLOR)fclean libft done!$(NO_COLOR)"

message:
	@echo "$(WARN_COLOR)Restart in process...$(NO_COLOR)"

re: fclean message all

-include $(DEPS)

.PHONY: all clean fclean re

NO_COLOR		=	\x1b[0m
OK_COLOR		=	\x1b[32;01m
WARN_COLOR		=	\x1b[33;01m
BLUE_COLOR		=	\x1b[34;01m
