/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:09:21 by ifaleh            #+#    #+#             */
/*   Updated: 2025/09/10 18:36:21 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	my_put_pixel(char *data, t_source *src, int x, int y, int color)
{
	int		 pos;

	pos = (y * src->line_len + x * (src->bpp / 8));
	if (x >= 0 && x < src->width && y >= 0 && y < src->height)
		*(unsigned int *)(data + pos)= color;
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
	y = 0;
	x = 0;
	half = src->height / 2;
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
		
	}
	mlx_put_image_to_window(src->mlx_pointer, src->mlx_window, src->render_image, 0, 0);
	return (0);
}
