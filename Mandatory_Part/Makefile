NAME = cub3D

PARSER_SRC = \
	main.c

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
	Parssing/Libft_utils/ft_is_spaces.c \
	Parssing/Libft_utils/ft_strstr.c \

UTILS_SRC = \
	Parssing/Utils_func/print_messages.c \
	Parssing/Utils_func/ft_get_next_line.c \
	Parssing/Utils_func/ft_check_valid_source.c \
	Parssing/Utils_func/ft_fill_struct.c \
	Parssing/Utils_func/ft_fill_the_map.c \
	Parssing/Utils_func/ft_check_before_map.c \
	Parssing/Utils_func/ft_parsing.c \
	Parssing/Utils_func/ft_get_source.c \
	Parssing/Utils_func/ft_debug.c \
	Parssing/Utils_func/ft_parse_map.c \
	Parssing/Utils_func/ft_parse_map2.c \
	Parssing/Utils_func/ft_parse_map3.c \
	Parssing/Utils_func/ft_key_theme.c \
	Parssing/Utils_func/ft_secound_parsing.c \
	Parssing/Utils_func/ft_add_spaces_in_map.c \
	Parssing/Utils_func/keys.c\
	Parssing/Utils_func/ft_lenght_j.c\

RAY_FUNC = \
	raycasting/init_player.c\
	raycasting/init_text.c\
	raycasting/raycast.c\
	raycasting/utils.c\
	raycasting/render.c\

SRC = $(PARSER_SRC) $(LIBFT_SRC) $(UTILS_SRC) $(RAY_FUNC)
OBJS = $(SRC:.c=.o)

CC = cc -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror -IParssing -IParssing/Libft_utils -IParssing/Utils_func
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) cub_mand.h
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
