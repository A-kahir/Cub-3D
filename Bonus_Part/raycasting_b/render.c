/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 04:19:39 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/11 20:03:05 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	render_cell_floor(t_source *src, char *data)
{
	int		x;
	int		y;
	int		half;
	t_pixel	p;

	x = 0;
	y = 0;
	half = HEIGHT / 2;
	while (y < half)
	{
		x = 0;
		while (x < WIDTH)
		{
			p.x = x;
			p.y = y;
			my_put_pixel(data, src, p, src->colors->hexa_rgb_f);
			p.x = x;
			p.y = (HEIGHT - y - 1);
			my_put_pixel(data, src, p, src->colors->hexa_rgb_c);
			x++;
		}
		y++;
	}
}

void	draw_wall_column(char *data, t_source *src, t_tex *tex, int params[4])
{
	t_wall_draw	w;

	w.tex = tex;
	init_wall_params(&w, params, src);
	w.p_ouvert = get_door_opening(src);
	draw_texture_line(data, src, &w, tex);
}

int	process_column(t_source *src, char *data, int i, int params[4])
{
	t_raycast	*ray;
	int			lineheight;
	int			draw_start;
	int			draw_end;
	t_tex		*tex;

	ray = src->ray;
	init_data(src, ray, &i);
	init_side_dest(src, ray);
	while (ray->hit == 0)
		if (dda(src, ray) == 1)
			break ;
	calculate_wall_params(ray, &lineheight);
	calculate_draw_limits(lineheight, &draw_start, &draw_end);
	tex = select_texture(src, ray);
	params[0] = i;
	params[1] = draw_start;
	params[2] = draw_end;
	params[3] = lineheight;
	draw_wall_column(data, src, tex, params);
	return (0);
}

void	keys(t_source *src, int *i, double *time)
{
	handle_mouse(src);
	key_events(src);
	norm_render(src, i, time);
}

int	render_frame(t_source *src)
{
	char		*data;
	int			i;
	t_raycast	*ray;
	double		time;
	int			params[4];

	keys(src, &i, &time);
	ray = malloc_cl(sizeof(t_raycast), 0);
	if (!ray)
		return (ft_free_mlx(src), malloc_cl(0, 2), -1);
	if (!src->render_image)
		return (0);
	src->ray = ray;
	data = mlx_get_data_addr(src->render_image, &src->bpp,
			&src->line_len, &src->endian);
	if (!data)
		return (ft_free_mlx(src), malloc_cl(0, 2), -1);
	ft_memset(data, 0, WIDTH * HEIGHT * (src->bpp / 8));
	render_cell_floor(src, data);
	while (++i < WIDTH)
		process_column(src, data, i, params);
	ft_mini_map(src);
	mlx_put_image_to_window(src->mlx_pointer, src->mlx_window,
		src->render_image, 0, 0);
	return (0);
}
