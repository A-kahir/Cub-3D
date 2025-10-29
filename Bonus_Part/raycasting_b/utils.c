/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 03:58:42 by ifaleh            #+#    #+#             */
/*   Updated: 2025/10/29 07:48:43 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int	get_map_height(char **map)
{
	int	h;

	h = 0;
	while (map[h])
		h++;
	return (h);
}

int	get_map_width(char **map)
{
	int	max_w;
	int	i;
	int	len;

	max_w = 0;
	i = 0;
	while (map[i])
	{
		len = strlen(map[i]);
		if (len > max_w)
			max_w = len;
		i++;
	}
	return (max_w);
}

void	my_put_pixel(char *data, t_source *src, int x, int y, int color)
{
	int	pos;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pos = (y * src->line_len + x * (src->bpp / 8));
	*(unsigned int *)(data + pos) = color;
}

void	dda_norm(t_raycast *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->mapx += ray->stepx;
		ray->side = 0;
		if (ray->ray_dir_x < 0)
			ray->wall_dir = 3;
		else
			ray->wall_dir = 2;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->mapy += ray->stepy;
		ray->side = 1;
		if (ray->ray_dir_y > 0)
			ray->wall_dir = 0;
		else
			ray->wall_dir = 1;
	}
}
