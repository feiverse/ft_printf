NAME 		= libftprintf.a
LIBFT		= libft/libft.a

CC			= clang
CFLAGS		= -g3 -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -rf

INC			= inc/ft_printf.h

SRC_DIR		:= src
SRC			:= ft_printf.c \
			print_basic.c \
			print_format.c \
			print_helpers.c \
			print_numbers.c \
			print_utils.c 
SRC			:= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR		:= obj
OBJ			:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME) $(OBJ_DIR)

re: fclean all

.PHONY: all bonus clean fclean re


DEFAULT=\033[0m
BOLD=\033[1m
ITALIC=\033[3m

BLACK=\033[30m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m