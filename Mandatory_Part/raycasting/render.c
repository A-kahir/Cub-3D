/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 04:19:39 by ifaleh            #+#    #+#             */
/*   Updated: 2025/09/23 18:11:39 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

// void	render_cell_floor(t_source *src, char *data)
// {
// 	int	x;
// 	int	y;
// 	int	half;

// 	x = 0;
// 	y = 0;
// 	half = src->height / 2;
// 	while (y < half)
// 	{
// 		x = 0;
// 		while (x < src->width)
// 		{
// 			my_put_pixel(data, src, x, y, src->colors->hexa_rgb_f);
// 			my_put_pixel(data, src, x, (src->height - y - 1),
// 				src->colors->hexa_rgb_c);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	calc_texture(t_source *src, t_raycast *ray, t_tex **tex, int *tex_x)
// {
// 	double	wall_x;

// 	if (ray->side == 0)
// 		wall_x = src->p->p_py + ray->perpwalldis * ray->ray_dir_y;
// 	else
// 		wall_x = src->p->p_px + ray->perpwalldis * ray->ray_dir_x;
// 	wall_x -= floor(wall_x);
// 	if (ray->wall_dir == 0)
// 		*tex = &src->no_tex;
// 	else if (ray->wall_dir == 1)
// 		*tex = &src->sud_tex;
// 	else if (ray->wall_dir == 2)
// 		*tex = &src->west_tex;
// 	else
// 		*tex = &src->est_tex;
// 	*tex_x = (int)(wall_x * (double)(*tex)->width);
// 	if ((ray->side == 0 && ray->ray_dir_x > 0)
// 		|| (ray->side == 1 && ray->ray_dir_y < 0))
// 		*tex_x = (*tex)->width - *tex_x - 1;
// 	if (*tex_x < 0 || *tex_x >= (*tex)->width)
// 	{
// 		perror("Error\ntexX out of bounds\n");
// 		*tex_x = (*tex_x < 0) ? 0 : (*tex)->width - 1;
// 	}
// }

// void	draw_wall_textured(t_source *src, t_tex *tex, int x, char *data)
// {
// 	int		y;
// 	int		tex_y;
// 	int		start;
// 	int		end;
// 	double	tex_pos;

// 	start = src->draw_start;
// 	end = src->draw_end;
// 	if (!tex->data || !tex->image)
// 	{
// 		perror("Error\nInvalid texture\n");
// 		return ;
// 	}
// 	y = start;
// 	while (y <= end)
// 	{
// 		tex_pos = (y - src->height / 2.0 + (end - start + 1) / 2.0)
// 			* tex->height / (end - start + 1);
// 		tex_y = (int)tex_pos % tex->height;
// 		if (tex_y < 0 || tex_y >= tex->height)
// 			tex_y = (tex_y < 0) ? 0 : tex->height - 1;
// 		my_put_pixel(data, src, x, y, *(unsigned int *)(tex->data
// 				+ (tex_y * tex->line_len + src->tex_x * (tex->bpp / 8))));
// 		y++;
// 	}
// }

// int	render_frame(t_source *src)
// {
// 	char		*data;
// 	t_raycast	*ray;
// 	int			x;
// 	t_tex		*tex;

// 	if (init_frame(src, &data))
// 		return (1);
// 	render_cell_floor(src, data);
// 	ray = malloc(sizeof(t_raycast));
// 	if (!ray)
// 		return (perror("Error\nMemory allocation failed\n"), 1);
// 	x = 0;
// 	while (x < src->width)
// 	{
// 		init_data(src, ray, &x);
// 		ray->hit = 0;
// 		ray->side = 0;
// 		ray->wall_dir = 0;
// 		dda_algo(src, ray);
// 		calc_wall_dist(src, ray);
// 		calc_wall_projection(src, ray, &src->draw_start, &src->draw_end);
// 		calc_texture(src, ray, &tex, &src->tex_x);
// 		draw_wall_textured(src, tex, x, data);
// 		x++;
// 	}
// 	free(ray);
// 	mlx_put_image_to_window(src->mlx_pointer, src->mlx_window,
// 		src->render_image, 0, 0);
// 	return (0);
// }

int render_frame(t_source *src)
{
	int		half;
	int		y;
	int		x;
	char	*data;
	int		i;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		mapX;
	int		mapY;
	double		delta_dist_x;
	double		delta_dist_y;
	int		stepX;
	int		stepY;
	double	side_dist_x;
	double	side_dist_y;
	int		hit;
	int		side;
	double	perpwalldis;
	int		lineheight;
	int		draw_start;
	int		draw_end;
	int		drawing;
	double	time;
	int		wall_dir;

	y = 0;
	x = 0;
	i = 0;
	half = src->height / 2;
	src->map_h = get_map_height(src->map);
	src->map_w = get_map_width(src->map);
	time = get_time();
	src->frame_time = (time - src->old_time) / 1000;
	if (src->frame_time == 0)
		src->frame_time = 0.0001;
	src->old_time = time;
	if (!src->render_image)
		return (0);
	data = mlx_get_data_addr(src->render_image, &src->bpp, &src->line_len, &src->endian);
	if (!data)
		return (0);
	memset(data, 0, src->width * src->height * (src->bpp / 8));
	while (y < half)
	{
		x = 0;
		while (x < src->width)
		{
			my_put_pixel(data, src, x, y, src->colors->hexa_rgb_f);
			my_put_pixel(data, src, x, (src->height - y - 1), src->colors->hexa_rgb_c);
			x++;
		}
		y++;
	}
	while (i < src->width)
	{
		camera_x = 2 * i / (double)src->width - 1;
		ray_dir_x = src->p->dir_x + src->p->plan_x * camera_x;
		ray_dir_y = src->p->dir_y + src->p->plan_y * camera_x;
		mapX = (int)(src->p->p_px);
		mapY = (int)(src->p->p_py);
		delta_dist_x = fabs(1 / ray_dir_x);
		delta_dist_y = fabs(1 / ray_dir_y);
		if (ray_dir_x < 0)
		{
			stepX = -1;
			side_dist_x = (src->p->p_px - mapX) * delta_dist_x;
		}
		else
		{
			stepX = 1;
			side_dist_x = (mapX + 1.0 - src->p->p_px) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			stepY = -1;
			side_dist_y = (src->p->p_py - mapY) * delta_dist_y;
		}
		else
		{
			stepY = 1;
			side_dist_y = (mapY + 1.0 - src->p->p_py) * delta_dist_y;
		}
		hit = 0;
		side = 0;
		wall_dir = 0;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				mapX += stepX;
				side = 0;
				wall_dir = (ray_dir_x < 0) ? 3 : 2;
			}
			else
			{
				side_dist_y += delta_dist_y;
				mapY += stepY;
				side = 1;
				wall_dir = (ray_dir_y < 0) ? 0 : 1;
			}
			if (mapX < 0 || mapX >= src->map_w || mapY < 0 || mapY >= src->map_h)
			{
				hit = 1;
				break ;
			}
			if (src->map[mapY][mapX] == '1')
				hit = 1;
		}
		if (side == 0)
			perpwalldis = side_dist_x - delta_dist_x;
		else
			perpwalldis = side_dist_y - delta_dist_y;
		lineheight = (int)(src->height / perpwalldis);
		draw_start = -lineheight / 2 + src->height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = lineheight / 2 + src->height / 2;
		if (draw_end >= src->height)
			draw_end = src->height - 1;
		double wallX; // Position exacte où le rayon touche le mur
		if (side == 0)
			wallX = src->p->p_py + perpwalldis * ray_dir_y;
		else
			wallX = src->p->p_px + perpwalldis * ray_dir_x;
		wallX -= floor(wallX);

		t_tex *tex;
		if (wall_dir == 0)
			tex = &src->no_tex;
		else if (wall_dir == 1)
			tex = &src->sud_tex;
		else if (wall_dir == 2)
			tex = &src->west_tex;
		else
			tex = &src->est_tex;

		// Vérifier que la texture est valide
		if (!tex->data || !tex->image)
		{
			printf("Error: Texture invalid for wall_dir=%d\n", wall_dir);
			for (int drawing = draw_start; drawing <= draw_end; drawing++)
				my_put_pixel(data, src, i, drawing, 0xFF0000); // Rouge pour indiquer une erreur
			i++;
			continue;
		}

		int texX = (int)(wallX * (double)tex->width);
		if ((side == 0 && ray_dir_x > 0) || (side == 1 && ray_dir_y < 0))
			texX = tex->width - texX - 1;

		// Vérifier les limites de texX
		if (texX < 0 || texX >= tex->width)
		{
			printf("Error: texX=%d out of bounds (width=%d)\n", texX, tex->width);
			texX = (texX < 0) ? 0 : tex->width - 1;
		}

		drawing = draw_start;
		while (drawing <= draw_end)
		{
			double texPos = (drawing - src->height / 2.0 + lineheight / 2.0) * tex->height / lineheight;
			int texY = (int)texPos % tex->height;
			if (texY < 0 || texY >= tex->height)
			{
				printf("Error: texY=%d out of bounds (height=%d)\n", texY, tex->height);
				texY = (texY < 0) ? 0 : tex->height - 1;
			}
			int color = *(unsigned int *)(tex->data + (texY * tex->line_len + texX * (tex->bpp / 8)));
			my_put_pixel(data, src, i, drawing, color);
			drawing++;
		}
		i++;
	}
	mlx_put_image_to_window(src->mlx_pointer, src->mlx_window, src->render_image, 0, 0);
	return (0);
}
