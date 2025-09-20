NAME = cub3D

PARSER_SRC = \
	main.c

LIBFT_SRC = \
	Parssing_l/Libft_utils/malloc.c \
	Parssing_l/Libft_utils/ft_strcmp.c \
	Parssing_l/Libft_utils/ft_strdup.c \
	Parssing_l/Libft_utils/ft_strchr.c \
	Parssing_l/Libft_utils/ft_strjoin.c \
	Parssing_l/Libft_utils/ft_strlen.c \
	Parssing_l/Libft_utils/ft_strncmp.c \
	Parssing_l/Libft_utils/ft_add_back.c \
	Parssing_l/Libft_utils/ft_split.c \
	Parssing_l/Libft_utils/ft_atoi.c \
	Parssing_l/Libft_utils/ft_is_spaces.c \
	Parssing_l/Libft_utils/ft_strstr.c \

UTILS_SRC = \
	Parssing_l/Utils_func/print_messages.c \
	Parssing_l/Utils_func/ft_get_next_line.c \
	Parssing_l/Utils_func/ft_check_valid_source.c \
	Parssing_l/Utils_func/ft_fill_struct.c \
	Parssing_l/Utils_func/ft_fill_the_map.c \
	Parssing_l/Utils_func/ft_check_before_map.c \
	Parssing_l/Utils_func/ft_parsing.c \
	Parssing_l/Utils_func/ft_get_source.c \
	Parssing_l/Utils_func/ft_debug.c \
	Parssing_l/Utils_func/ft_parse_map.c \
	Parssing_l/Utils_func/ft_key_theme.c \
	Parssing_l/Utils_func/ft_secound_parsing.c \
	Parssing_l/Utils_func/ft_is_hell.c \
	Parssing_l/Utils_func/ft_add_spaces_in_map.c \
	Parssing_l/Utils_func/ft_mini_map_bonus.c \
	# Parssing_l/Utils_func/raycasting.c \

RAY_FUNC = \
	raycasting/init.c\
	raycasting/raycast.c\

SRC = $(PARSER_SRC) $(LIBFT_SRC) $(UTILS_SRC) $(RAY_FUNC)
OBJS = $(SRC:.c=.o)

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a
CC = cc -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror -IParssing -IParssing/Libft_utils -IParssing/Utils_func -I$(MLX_DIR)
MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) cub_mand.h
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re

# NAME = cub3D

# PARSER_SRC = \
# 	Parssing/main.c

# LIBFT_SRC = \
# 	Parssing/Libft_utils/malloc.c \
# 	Parssing/Libft_utils/ft_strcmp.c \
# 	Parssing/Libft_utils/ft_strdup.c \
# 	Parssing/Libft_utils/ft_strchr.c \
# 	Parssing/Libft_utils/ft_strjoin.c \
# 	Parssing/Libft_utils/ft_strlen.c \
# 	Parssing/Libft_utils/ft_strncmp.c \
# 	Parssing/Libft_utils/ft_add_back.c \
# 	Parssing/Libft_utils/ft_split.c \
# 	Parssing/Libft_utils/ft_atoi.c \
# 	Parssing/Libft_utils/ft_is_spaces.c \

# UTILS_SRC = \
# 	Parssing/Utils_func/print_messages.c \
# 	Parssing/Utils_func/ft_get_next_line.c \
# 	Parssing/Utils_func/ft_check_valid_source.c \
# 	Parssing/Utils_func/ft_fill_struct.c \
# 	Parssing/Utils_func/ft_fill_the_map.c \
# 	Parssing/Utils_func/ft_check_before_map.c \
# 	Parssing/Utils_func/ft_parsing.c \
# 	Parssing/Utils_func/ft_get_source.c \
# 	Parssing/Utils_func/ft_debug.c \
# 	Parssing/Utils_func/ft_parse_map.c \
# 	Parssing/Utils_func/ft_key_theme.c \
# 	Parssing/Utils_func/ft_secound_parsing.c \
# 	Parssing/Utils_func/ft_is_hell.c \
# 	Parssing/Utils_func/raycasting.c \

# SRC = $(PARSER_SRC) $(LIBFT_SRC) $(UTILS_SRC)
# OBJS = $(SRC:.c=.o)

# CC = cc -fsanitize=address -g
# CFLAGS = -Wall -Wextra -Werror -IParssing -IParssing/Libft_utils -IParssing/Utils_func
# MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# all: $(NAME)

# $(NAME): $(OBJS) Parssing/parsing.h
# 	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: clean fclean re
