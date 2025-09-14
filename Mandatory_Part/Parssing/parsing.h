/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:08:37 by akahir            #+#    #+#             */
/*   Updated: 2025/08/15 16:08:37 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55
# endif

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <mlx.h>
# include <math.h>


typedef enum s_mal
{
	ALLOCATION,
	FREE,
}	t_mal;

typedef struct s_leaks
{
	char			*ptr;
	struct s_leaks	*next;
}	t_leaks;

typedef struct s_colors
{
	unsigned int hexa_rgb_f;
	unsigned int hexa_rgb_c;
}	t_colors;

typedef struct s_player
{
	int		player_px;
	int		player_py;
	char	player_or;
} t_player;

typedef struct s_source
{
	char			*var;
	char			*value;
	char			**map;
	void			*mlx_pointer;
	void			*mlx_window;
	void			*mlx_image;
	int				hight;
	int				width;
	t_colors		*colors;
	t_player		*player;
	struct s_source	*next;
}	t_source;


//principale func:
int			ft_parsing(int argc, char **argv);
t_source	*ft_get_source(t_source *src, char *file);
void		ft_is_hell(t_source *src);

//Utils func:
void		print_message(int flag, char *arg, char ch);
char		*ft_get_next_line(int fd);
int			ft_chack_valid_source(char *str);
t_source	 *ft_fill_struct(t_source *src, char *line);
void		*ft_fill_the_map(int fd, t_source *src);
int			ft_check_before_map(t_source *src);
int			ft_parse_map(t_source *src);
int			ft_key_theme(int key, t_source *src);
int			ft_key_loading(int key, t_source *src);
void		ft_secound_parsing(t_source *src);
void		ft_add_spaces_in_map(t_source *src);
int			ft_max_len(t_source *src);

//Libft utils:
void		*malloc_cl(size_t size, t_mal mode);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *s1, int flag);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char	*str);
char		*ft_strstr(char *haystack, char *needle);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char *s, char c);
t_source	*ft_add_back(t_source *line, char *var, char *value);
int			ft_atoi(char *str);
int			ft_is_spaces(char c);
int			ft_lenght_j(t_source *src);


/// should remove when we finish
void ft_debug(t_source *src, int flag); // in utils func





void	ft_mini_map(t_source *src); // Utils_func ==> bonus part
int ft_key_move_player(int key, t_source *src); // utils_func ==> bonut part(move player in minimap);
#endif