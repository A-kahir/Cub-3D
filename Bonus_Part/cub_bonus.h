/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mand.h                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:08:37 by akahir            #+#    #+#             */
/*   Updated: 2025/08/15 16:08:37 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55
# endif

# define WIDTH 1472
# define HEIGHT 832

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
# include <sys/time.h>

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

typedef struct s_minimp
{
	int	view;
	int	mini_size;
	int	left_off;
	int	top_off;
	int	start_x;
	int	end_x;
	int	start_y;
	int	end_y;
	int	map_width;
	int	map_height;
}	t_minimp;

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
	int		door_id;
	int		tex_x;
}	t_raycast;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

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
	char	*path;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_doors
{
	int				index;
	int				x;
	int				y;
	int				etat;
	double			p_ouvert;
	double			timer;
	struct s_doors	*next;
}	t_doors;

typedef struct s_chars
{
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
	int			dr;
}	t_chars;

typedef struct s_sp_infos
{
	int		h;
	int		w;
	int		i;
	char	*path;
	void	*sprite;
	int		sp_x;
	int		sp_y;
}	t_sp_infos;

typedef struct s_wall_draw
{
	int		i;
	int		draw_start;
	int		draw_end;
	int		lineheight;
	int		drawing;
	int		tex_x;
	double	p_ouvert;
	t_tex	*tex;

}	t_wall_draw;

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
	t_tex			doors_tex;
	t_colors		*colors;
	t_player		*p;
	t_doors			*door;
	t_raycast		*ray;
	t_minimp		*mmp;
	int				color;
	struct s_source	*next;
}	t_source;

//principale func:
int			ft_parsing(int argc, char **argv);
t_source	*ft_get_source(t_source *src, char *file);
void		ft_is_hell(t_source *src);

//Utils func:
void		print_message(int flag, char *arg, char ch);
char		*ft_get_next_line(int fd);
int			ft_chack_valid_source(t_source *src, char *str);
t_source	*ft_fill_struct(t_source *src, char *line);
void		*ft_fill_the_map(int fd, t_source *src);
int			ft_check_before_map(t_source *src);
int			ft_parse_map(t_source *src);
int			ft_key_theme_b(int key, t_source *src);
int			ft_key_loading(int key, t_source *src);
void		ft_sec_parsing(t_source *src);
void		ft_add_spaces_in_map(t_source *src);
int			ft_max_len(t_source *src);
char		ft_check(t_source *src, int r, int c);
int			check_args1(t_source *src);
int			ft_static_flag(int new_nb, int flag);
int			ft_stop_reading(t_source *src);

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
int			check_corner_and_side(t_source *src, int i, int l);
int			ft_check_corners(t_source *src, int i, int l);
int			ft_check_middle_chars(t_source *src, int i, int len_j);
int			ft_check_spaces_zone(t_source *src, int i, int l, int len_i);
int			ft_valid_char_rows(t_source *src, int i, int len_j);
void		ft_free_mlx(t_source *src);
char		*ft_itoa(int n);

//init data
void		init_player(t_source *src);
void		init_text(t_source *src);

// drawing
void		init_wall_params(t_wall_draw *w, int params[4], t_source *src);
double		get_door_opening(t_source *src);
int			get_adjusted_tex_x(t_wall_draw *w, t_tex *tex);
int			get_texture_color(t_tex *tex, int tex_x, int tex_y);
void		draw_texture_line(char *data, t_source *src, t_wall_draw *w,
			t_tex *tex);
//utils raycasting
int			get_map_height(char **map);
int			get_map_width(char **map);
void		my_put_pixel(char *data, t_source *src, t_pixel p, int color);
void		init_data(t_source *src, t_raycast *ray, int *i);
int			dda(t_source *src, t_raycast *ray);
void		init_side_dest(t_source *src, t_raycast *ray);
void		calculate_wall_params(t_raycast *ray,
				int *lineheight);
void		calculate_draw_limits(int lineheight,
				int *draw_start, int *draw_end);
t_tex		*select_texture(t_source *src, t_raycast *ray);
int			calculate_tex_x(t_source *src, t_raycast *ray, t_tex *tex);

// rendering floor celling
int			render_frame(t_source *src);

/// should remove when we finish
void		ft_debug_map(char *map, int pos); // in utils func
void		ft_debug(t_source *src, int flag); // in utils func

//timing
long		get_time(void);

//keys
int			key_events(int key, t_source *src);
void		norm_keys2(int key, t_source *src, double move_speed);
void		norm_keys1(int key, t_source *src, double move_speed);
void		norm_key_fleche(int key, t_source *src, double r_speed);
void		norm_mouse(t_source *src, double rot_speed, int delta_x);
void		norm_key3(int key, t_source *src);
// Bonus func :

	//-> conditions mmp
void		ft_calc_demonsions(t_minimp *mmp);
void		ft_fix_negative(t_minimp *mmp);
void		ft_cadring_outside(t_minimp *mmp, int map_w, int map_h);
void		ft_init_minimap(t_minimp *mmp, t_source *src);
	//-> draw Pixels
void		ft_set_pixel_img(t_source *src, char *img_data, t_pixel pixel,
				int color);
void		ft_draw_pixel(t_source *src, char *img_data,
				t_minimp *mmp, int color);
void		ft_render_tiles(t_source *src, char *img_data, t_minimp *mmp);
int			ft_get_color_pixel(t_source *src, int i, int j);
void		ft_add_door(t_source *src, int x, int y, int index);

//doors
int			ft_door(t_source *src, int mapx, int mapy);
int			door_state(t_source *src, int index);
void		update_door_animation(t_source *src);
int			ft_check_player(t_source *src);
t_source	*ft_read_lines(int fd, t_source *src);
int			key_animation(int key, t_source *src);
int			ft_check_up_bottom_valid_chars(t_source *src, int len_j);
void		dda_norm(t_raycast *ray);

#endif