NAME = cub3D

PARSER_SRC = \
	Parssing/main.c

LIBFT_SRC = \
	Parssing/Libft_utils/malloc.c \
	Parssing/Libft_utils/ft_strcmp.c \
	Parssing/Libft_utils/ft_strdup.c \
	Parssing/Libft_utils/ft_strchr.c \
	Parssing/Libft_utils/ft_strjoin.c \
	Parssing/Libft_utils/ft_strlen.c \

UTILS_SRC = \
	Parssing/Utils_func/print_messages.c \
	Parssing/Utils_func/ft_get_next_line.c \

SRC = $(PARSER_SRC) $(LIBFT_SRC) $(UTILS_SRC)
OBJS = $(SRC:.c=.o)

MLX_DIR = ../MLX42
MLX_FILE = $(MLX_DIR)/build/libmlx42.a
BREW_PREFIX := $(shell brew --prefix)
MLX_FLAGS = -L$(BREW_PREFIX)/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)/include -IParssing -IParssing/Libft_utils -IParssing/Utils_func

all: $(MLX_FILE) $(NAME)

$(NAME): $(OBJS) $(MLX_FILE) parsing.h
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FILE) $(MLX_FLAGS) -o $(NAME)

$(MLX_FILE):
	cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	cmake --build $(MLX_DIR)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
