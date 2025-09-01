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
	Parssing/Libft_utils/ft_atoi.c \

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
	Parssing/Utils_func/ft_debug.c \
	Parssing/Utils_func/ft_parse_map.c \

SRC = $(PARSER_SRC) $(LIBFT_SRC) $(UTILS_SRC)
OBJS = $(SRC:.c=.o)

CC = cc -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror -IParssing -IParssing/Libft_utils -IParssing/Utils_func
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) Parssing/parsing.h
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
