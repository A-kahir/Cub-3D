NAME = cub3D
NAME_BONUS = cub3D_bonus

PARSER_SRC = Mandatory_Part/main.c
PARSER_B   = Bonus_Part/main.c

LIBFT_SRC = \
	Mandatory_Part/Parssing/Libft_utils/alloc.c \
	Mandatory_Part/Parssing/Libft_utils/ft_strcmp.c \
	Mandatory_Part/Parssing/Libft_utils/ft_strdup.c \
	Mandatory_Part/Parssing/Libft_utils/ft_strchr.c \
	Mandatory_Part/Parssing/Libft_utils/ft_strjoin.c \
	Mandatory_Part/Parssing/Libft_utils/ft_strlen.c \
	Mandatory_Part/Parssing/Libft_utils/ft_strncmp.c \
	Mandatory_Part/Parssing/Libft_utils/ft_add_back.c \
	Mandatory_Part/Parssing/Libft_utils/ft_split.c \
	Mandatory_Part/Parssing/Libft_utils/ft_atoi.c \
	Mandatory_Part/Parssing/Libft_utils/ft_is_spaces.c \
	Mandatory_Part/Parssing/Libft_utils/ft_strstr.c \
	Mandatory_Part/Parssing/Libft_utils/ft_free_mlx.c \
	Mandatory_Part/Parssing/Libft_utils/ft_itoa.c \
	Mandatory_Part/Parssing/Libft_utils/ft_bzero.c \
	Mandatory_Part/Parssing/Libft_utils/ft_memset.c

LIBFT_SRCB = \
	Bonus_Part/Parssing_b/Libft_utils/alloc_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_strcmp_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_strdup_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_strchr_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_strjoin_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_strlen_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_strncmp_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_add_back_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_split_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_atoi_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_is_spaces_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_strstr_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_free_mlx_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_itoa_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_bzero_bonus.c \
	Bonus_Part/Parssing_b/Libft_utils/ft_memset_bonus.c

UTILS_SRC = \
	Mandatory_Part/Parssing/Utils_func/print_messages.c \
	Mandatory_Part/Parssing/Utils_func/ft_get_next_line.c \
	Mandatory_Part/Parssing/Utils_func/ft_check_valid_source.c \
	Mandatory_Part/Parssing/Utils_func/ft_fill_struct.c \
	Mandatory_Part/Parssing/Utils_func/ft_fill_the_map.c \
	Mandatory_Part/Parssing/Utils_func/ft_check_before_map.c \
	Mandatory_Part/Parssing/Utils_func/ft_parsing.c \
	Mandatory_Part/Parssing/Utils_func/ft_get_source.c \
	Mandatory_Part/Parssing/Utils_func/ft_parse_map.c \
	Mandatory_Part/Parssing/Utils_func/ft_parse_map2.c \
	Mandatory_Part/Parssing/Utils_func/ft_parse_map3.c \
	Mandatory_Part/Parssing/Utils_func/ft_key_theme.c \
	Mandatory_Part/Parssing/Utils_func/ft_secound_parsing.c \
	Mandatory_Part/Parssing/Utils_func/ft_add_spaces_in_map.c \
	Mandatory_Part/Parssing/Utils_func/keys.c \
	Mandatory_Part/Parssing/Utils_func/keys_utils.c \
	Mandatory_Part/Parssing/Utils_func/ft_lenght_j.c \
	Mandatory_Part/Parssing/Utils_func/ft_static_flag.c \
	Mandatory_Part/Parssing/Utils_func/ft_check_player.c \
	Mandatory_Part/Parssing/Utils_func/ft_check_but.c

UTILS_SRC_B = \
	Bonus_Part/Parssing_b/Utils_func/print_messages_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_get_next_line_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_check_valid_source_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_fill_struct_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_fill_the_map_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_check_before_map_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_parsing_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_get_source_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_parse_map_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_parse_map2_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_parse_map3_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_key_theme_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_secound_parsing_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_add_spaces_in_map_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/keys_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_lenght_j_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_is_hell_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_mini_map_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_mini_map_conditions_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_draw_pixels_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_static_flag_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_add_door_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_check_player_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/keys_2_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/keys_utils_bonus.c \
	Bonus_Part/Parssing_b/Utils_func/ft_check_but_bonus.c 

RAY_FUNC = \
	Mandatory_Part/raycasting/init_player.c \
	Mandatory_Part/raycasting/init_text.c \
	Mandatory_Part/raycasting/raycast.c \
	Mandatory_Part/raycasting/utils.c \
	Mandatory_Part/raycasting/render.c \
	Mandatory_Part/raycasting/draw.c

RAY_FUNC_B = \
	Bonus_Part/raycasting_b/init_player_bonus.c \
	Bonus_Part/raycasting_b/init_text_bonus.c \
	Bonus_Part/raycasting_b/raycast_bonus.c \
	Bonus_Part/raycasting_b/utils_bonus.c \
	Bonus_Part/raycasting_b/render_bonus.c \
	Bonus_Part/raycasting_b/doors_bonus.c \
	Bonus_Part/raycasting_b/draw_bonus.c

SRC   = $(PARSER_SRC) $(LIBFT_SRC) $(UTILS_SRC) $(RAY_FUNC)
SRC_B = $(PARSER_B)   $(LIBFT_SRCB) $(UTILS_SRC_B) $(RAY_FUNC_B)

OBJS = $(SRC:.c=.o)
OBJB = $(SRC_B:.c=.o)

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g\
         -IMandatory_Part/Parssing \
         -IMandatory_Part/Parssing/Libft_utils \
         -IMandatory_Part/Parssing/Utils_func \
         -IBonus_Part/Parssing_b \
         -IBonus_Part/Parssing_b/Libft_utils \
         -IBonus_Part/Parssing_b/Utils_func \
		 -I$(MLX_DIR)

MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) Mandatory_Part/cub_mand.h
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJB) Bonus_Part/cub_bonus.h
	$(CC) $(CFLAGS) $(OBJB) $(MLXFLAGS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJB)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
# -fsanitize=address -g