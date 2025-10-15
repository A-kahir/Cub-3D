/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 04:19:39 by ifaleh            #+#    #+#             */
/*   Updated: 2025/10/15 20:33:45 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	render_cell_floor(t_source *src, char *data)
{
	int	x;
	int	y;
	int	half;

	x = 0;
	y = 0;
	half = HEIGHT / 2;
	while (y < half)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_put_pixel(data, src, x, y, src->colors->hexa_rgb_f);
			my_put_pixel(data, src, x, (HEIGHT - y - 1),
				src->colors->hexa_rgb_c);
			x++;
		}
		y++;
	}
}

void	draw_wall_column(char *data, t_source *src, t_tex *tex, int params[4])
{
	int		drawing;
	double	texPos;
	int		texY;
	int		color;
	int		i = params[0];
	int		draw_start = params[1];
	int		draw_end = params[2];
	int		lineheight = params[3];
	int		tex_x;
	double	p_ouvert = 0.0;

	tex_x = calculate_tex_x(src, src->ray, tex);
	drawing = draw_start;
	if (src->ray->wall_dir == 4)
    {
        t_doors *current = src->door;
        while (current && current->index != src->ray->door_id)
            current = current->next;
        if (current)
            p_ouvert = current->p_ouvert;
    }
	while (drawing <= draw_end)
	{
		texPos = (drawing - HEIGHT / 2.0 + lineheight / 2.0)
			* tex->height / lineheight;
		texY = (int)texPos % tex->height;
		if (texY < 0 || texY >= tex->height)
		{
			printf("Error: texY=%d out of bounds (height=%d)\n", texY, tex->height);
			if (texY < 0)
				texY = 0;
			else
				texY = tex->height - 1;
		}
		int adjusted_tex_x = tex_x;
        if (src->ray->wall_dir == 4)
            adjusted_tex_x = tex_x + (int)(p_ouvert * tex->width);
        if (adjusted_tex_x >= tex->width)
            adjusted_tex_x = tex->width - 1;
		color = *(unsigned int *)(tex->data + (texY * tex->line_len + adjusted_tex_x
					* (tex->bpp / 8)));
		my_put_pixel(data, src, i, drawing, color);
		drawing++;
	}
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

int	render_frame(t_source *src)
{
	char		*data;
	int			i;
	t_raycast	*ray;
	double		time;
	int			params[4];

	i = -1;
	time = get_time();
	src->frame_time = (time - src->old_time) / 1000;
	if (src->frame_time == 0)
		src->frame_time = 0.0001;
	src->old_time = time;
	ray = malloc(sizeof(t_raycast));
	if (!ray)
		return (1);
	if (!src->render_image)
		return (0);
	src->ray = ray;
	data = mlx_get_data_addr(src->render_image, &src->bpp,
			&src->line_len, &src->endian);
	if (!data)
		return (0);
	memset(data, 0, WIDTH * HEIGHT * (src->bpp / 8));
	update_door_animation(src);
	render_cell_floor(src, data);
	while (++i < WIDTH)
		process_column(src, data, i, params);
	ft_mini_map(src);
	mlx_put_image_to_window(src->mlx_pointer, src->mlx_window,
		src->render_image, 0, 0);
	return (free(ray), 0);
}
