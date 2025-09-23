/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mand.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:08:37 by akahir            #+#    #+#             */
/*   Updated: 2025/08/15 16:08:37 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MAND_H
# define CUB_MAND_H

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
#include <sys/time.h>

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
	unsigned int	hexa_rgb_f;
	unsigned int	hexa_rgb_c;
}	t_colors;

typedef struct s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		mapx;
	int		mapy;
	double	delta_dist_x;
	double	delta_dist_y;
	int		stepx;
	int		stepy;
	double	side_dist_x;
	double	side_dist_y;
	int		hit;
	int		side;
	double	perpwalldis;
	int		wall_dir;
}	t_raycast;

typedef struct s_player
{
	double		p_px;
	double		p_py;
	double		dir_x;
	double		dir_y;
	double		plan_x;
	double		plan_y;
	char		p_or;
}	t_player;

typedef struct s_texture
{
	void	*image;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_source
{
	char			*var;
	char			*value;
	char			**map;
	void			*mlx_pointer;
	void			*mlx_window;
	void			*mlx_image;
	int				height;
	int				line_len;
	int				bpp;
	int				endian;
	int				width;
	long			old_time;
	double			frame_time;
	int				map_h;
	int				map_w;
	void			*render_image;
	t_tex			no_tex;
	t_tex			sud_tex;
	t_tex			est_tex;
	t_tex			west_tex;
	t_colors		*colors;
	t_player		*p;
	int				draw_start;
	int				draw_end;
	int				tex_x;
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
t_source	*ft_fill_struct(t_source *src, char *line);
void		*ft_fill_the_map(int fd, t_source *src);
int			ft_check_before_map(t_source *src);
int			ft_parse_map(t_source *src);
void		ft_key_theme(t_source *src);
int			ft_key_loading(int key, t_source *src);
void		ft_secound_parsing(t_source *src);
void		ft_add_spaces_in_map(t_source *src, int len);
int			ft_max_len(t_source *src);

//Libft utils:
void		*malloc_cl(size_t size, t_mal mode);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *s1, int flag);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char	*str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char *s, char c);
t_source	*ft_add_back(t_source *line, char *var, char *value);
int			ft_atoi(char *str);
int			ft_is_spaces(char c);
int			ft_lenght_j(t_source *src);
char		*ft_strstr(char *haystack, char *needle);

//init data
void		init_player(t_source *src);
void		init_text(t_source *src);

//utils raycasting
int			get_map_height(char **map);
int			get_map_width(char **map);
void		my_put_pixel(char *data, t_source *src, int x, int y, int color);
void		init_data(t_source *src, t_raycast *ray, int *i);
void		dda_algo(t_source *src, t_raycast *ray);
int			init_frame(t_source *src, char **data);
void		calc_wall_dist(t_source *src, t_raycast *ray);
void		calc_wall_projection(t_source *src,
				t_raycast *ray, int *start, int *end);
// rendering floor celling
int			render_frame(t_source *src);
/// should remove when we finish
void		ft_debug(t_source *src, int flag); // in utils func
//timing
long		get_time(void);

//keys
int			key_events(int key, t_source *src);
void		norm_keys2(int key, t_source *src, double move_speed);
void		norm_keys1(int key, t_source *src, double move_speed);
void		norm_key_fleche(int key, t_source *src, double r_speed);

int	ft_mini_map(t_source *src); // Utils_func ==> bonus part
int ft_key_move_player(int key, t_source *src); // utils_func ==> bonut part(move player in minimap);
#endif