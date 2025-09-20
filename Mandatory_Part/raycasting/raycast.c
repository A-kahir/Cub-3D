/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:24:58 by ifaleh            #+#    #+#             */
/*   Updated: 2025/09/20 19:47:15 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

int get_map_height(char **map)
{
	int h = 0;

	while (map[h])
		h++;
	return (h);
}

int get_map_width(char **map)
{
	int max_w = 0;
	int i = 0;
	while (map[i])
	{
		int len = strlen(map[i]);
		if (len > max_w)
			max_w = len;
		i++;
	}
	return (max_w);
}

void	my_put_pixel(char *data, t_source *src, int x, int y, int color)
{
	int	pos;

	if (x < 0 || x >= src->width || y < 0 || y >= src->height)
		return ;
	pos = (y * src->line_len + x * (src->bpp / 8));
	*(unsigned int *)(data + pos) = color;
}

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
	double	prepwalldis;
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
		ray_dir_x = src->player->dir_x + src->player->plan_x * camera_x;
		ray_dir_y = src->player->dir_y + src->player->plan_y * camera_x;
		mapX = (int)(src->player->player_px);
		mapY = (int)(src->player->player_py);
		delta_dist_x = fabs(1 / ray_dir_x);
		delta_dist_y = fabs(1 / ray_dir_y);
		if (ray_dir_x < 0)
		{
			stepX = -1;
			side_dist_x = (src->player->player_px - mapX) * delta_dist_x;
		}
		else
		{
			stepX = 1;
			side_dist_x = (mapX + 1.0 - src->player->player_px) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			stepY = -1;
			side_dist_y = (src->player->player_py - mapY) * delta_dist_y;
		}
		else
		{
			stepY = 1;
			side_dist_y = (mapY + 1.0 - src->player->player_py) * delta_dist_y;
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
			prepwalldis = side_dist_x - delta_dist_x;
		else
			prepwalldis = side_dist_y - delta_dist_y;
		lineheight = (int)(src->height / prepwalldis);
		draw_start = -lineheight / 2 + src->height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = lineheight / 2 + src->height / 2;
		if (draw_end >= src->height)
			draw_end = src->height - 1;
		double wallX; // Position exacte où le rayon touche le mur
		if (side == 0)
			wallX = src->player->player_py + prepwalldis * ray_dir_y;
		else
			wallX = src->player->player_px + prepwalldis * ray_dir_x;
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
