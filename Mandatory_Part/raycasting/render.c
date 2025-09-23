/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 04:19:39 by ifaleh            #+#    #+#             */
/*   Updated: 2025/09/24 00:23:51 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

void	render_cell_floor(t_source *src, char *data)
{
	int	x;
	int	y;
	int	half;

	x = 0;
	y = 0;
	half = src->height / 2;
	while (y < half)
	{
		x = 0;
		while (x < src->width)
		{
			my_put_pixel(data, src, x, y, src->colors->hexa_rgb_f);
			my_put_pixel(data, src, x, (src->height - y - 1),
				src->colors->hexa_rgb_c);
			x++;
		}
		y++;
	}
}

void	init_data(t_source *src, t_raycast *ray, int *i)
{
	ray->camera_x = 2 * (*i) / (double)src->width - 1;
	ray->ray_dir_x = src->p->dir_x + src->p->plan_x * ray->camera_x;
	ray->ray_dir_y = src->p->dir_y + src->p->plan_y * ray->camera_x;
	ray->mapx = (int)(src->p->p_px);
	ray->mapy = (int)(src->p->p_py);
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	init_side_dest(t_source *src, t_raycast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->stepx = -1;
		ray->side_dist_x = (src->p->p_px - ray->mapx) * ray->delta_dist_x;
	}
	else
	{
		ray->stepx = 1;
		ray->side_dist_x = (ray->mapx + 1.0 - src->p->p_px) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->stepy = -1;
		ray->side_dist_y = (src->p->p_py - ray->mapy) * ray->delta_dist_y;
	}
	else
	{
		ray->stepy = 1;
		ray->side_dist_y = (ray->mapy + 1.0 - src->p->p_py) * ray->delta_dist_y;
	}
	ray->hit = 0;
	ray->side = 0;
	ray->wall_dir = 0;
}

int	dda(t_source *src, t_raycast *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->mapx += ray->stepx;
		ray->side = 0;
		ray->wall_dir = (ray->ray_dir_x < 0) ? 3 : 2;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->mapy += ray->stepy;
		ray->side = 1;
		ray->wall_dir = (ray->ray_dir_y < 0) ? 0 : 1;
	}
	if (ray->mapx < 0 || ray->mapx >= src->map_w
		|| ray->mapy < 0 || ray->mapy >= src->map_h)
		return (ray->hit = 1, 1);
	if (src->map[ray->mapy][ray->mapx] == '1')
		ray->hit = 1;
	return (0);
}

int	render_frame(t_source *src)
{
	char		*data;
	int			i;
	t_raycast	*ray;
	int			lineheight;
	int			draw_start;
	int			draw_end;
	int			drawing;
	double		time;
	double		wallX;
	t_tex 		*tex;
	int 		tex_x;
	double		texPos;
	int			texY;
	int			color;

	i = 0;
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
	data = mlx_get_data_addr(src->render_image, &src->bpp, &src->line_len, &src->endian);
	if (!data)
		return (0);
	memset(data, 0, src->width * src->height * (src->bpp / 8));
	render_cell_floor(src, data);
	while (i < src->width)
	{
		init_data(src, ray, &i);
		init_side_dest(src, ray);
		while (ray->hit == 0)
			if (dda(src, ray) == 1)
				break ;
		if (ray->side == 0)
			ray->perpwalldis = ray->side_dist_x - ray->delta_dist_x;
		else
			ray->perpwalldis = ray->side_dist_y - ray->delta_dist_y;
		lineheight = (int)(src->height / ray->perpwalldis);
		draw_start = -lineheight / 2 + src->height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = lineheight / 2 + src->height / 2;
		if (draw_end >= src->height)
			draw_end = src->height - 1;
		if (ray->side == 0)
			wallX = src->p->p_py + ray->perpwalldis * ray->ray_dir_y;
		else
			wallX = src->p->p_px + ray->perpwalldis * ray->ray_dir_x;
		wallX -= floor(wallX);
		if (ray->wall_dir == 0)
			tex = &src->no_tex;
		else if (ray->wall_dir == 1)
			tex = &src->sud_tex;
		else if (ray->wall_dir == 2)
			tex = &src->west_tex;
		else
			tex = &src->est_tex;
		tex_x = (int)(wallX * (double)tex->width);
		if ((ray->side == 0 && ray->ray_dir_x > 0)
			|| (ray->side == 1 && ray->ray_dir_y < 0))
			tex_x = tex->width - tex_x - 1;
		if (tex_x < 0 || tex_x >= tex->width)
		{
			printf("Error: tex_x=%d out of bounds (width=%d)\n",
				tex_x, tex->width);
			if (tex < 0)
				tex_x = 0;
			else
				tex_x = tex->width - 1;
		}
		drawing = draw_start;
		while (drawing <= draw_end)
		{
			texPos = (drawing - src->height / 2.0 + lineheight / 2.0)
				* tex->height / lineheight;
			texY = (int)texPos % tex->height;
			if (texY < 0 || texY >= tex->height)
			{
				printf("Error: texY=%d out of bounds (height=%d)\n", texY, tex->height);
				if (tex < 0)
					tex_x = 0;
				else
					tex_x = tex->width - 1;
			}
			color = *(unsigned int *)(tex->data + (texY * tex->line_len + tex_x
						* (tex->bpp / 8)));
			my_put_pixel(data, src, i, drawing, color);
			drawing++;
		}
		i++;
	}
	mlx_put_image_to_window(src->mlx_pointer, src->mlx_window, src->render_image, 0, 0);
	return (0);
}
