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
	Parssing/Libft_utils/ft_strncmp.c \
	Parssing/Libft_utils/ft_add_back.c \
	Parssing/Libft_utils/ft_split.c \

UTILS_SRC = \
	Parssing/Utils_func/print_messages.c \
	Parssing/Utils_func/ft_get_next_line.c \
	Parssing/Utils_func/ft_check_valid_source.c \
	Parssing/Utils_func/ft_fill_struct.c \
	Parssing/Utils_func/ft_if_valid_map.c \
	Parssing/Utils_func/ft_fill_the_map.c \
	Parssing/Utils_func/ft_check_map.c \
	Parssing/Utils_func/ft_check_before_map.c \
	Parssing/Utils_func/ft_parsing.c \
	Parssing/Utils_func/ft_get_source.c \
	Parssing/Utils_func/ft_debug.c \ #should remove when we finish

SRC = $(PARSER_SRC) $(LIBFT_SRC) $(UTILS_SRC)
OBJS = $(SRC:.c=.o)

MLX_DIR = ../MLX42
MLX_FILE = $(MLX_DIR)/build/libmlx42.a
BREW_PREFIX := $(shell brew --prefix)
MLX_FLAGS = -L$(BREW_PREFIX)/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit

CC = cc -fsanitize=address -g
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
