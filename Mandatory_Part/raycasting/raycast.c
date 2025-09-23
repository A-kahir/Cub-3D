/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:24:58 by ifaleh            #+#    #+#             */
/*   Updated: 2025/09/23 04:29:32 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

void	init_data(t_source *src, t_raycast *ray, int *i)
{
	ray->camera_x = 2 * (*i) / (double)src->width - 1;
	ray->ray_dir_x = src->p->dir_x + src->p->plan_x * ray->camera_x;
	ray->ray_dir_y = src->p->dir_y + src->p->plan_y * ray->camera_x;
	ray->mapx = (int)(src->p->p_px);
	ray->mapy = (int)(src->p->p_py);
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
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
}

void	dda_algo(t_source *src, t_raycast *ray)
{
	while (ray->hit == 0)
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
		{
			ray->hit = 1;
			break ;
		}
		if (src->map[ray->mapy][ray->mapx] == '1')
			ray->hit = 1;
	}
}

int	init_frame(t_source *src, char **data)
{
	double	time;

	src->map_h = get_map_height(src->map);
	src->map_w = get_map_width(src->map);
	time = get_time();
	src->frame_time = (time - src->old_time) / 1000;
	if (src->frame_time == 0)
		src->frame_time = 0.0001;
	src->old_time = time;
	if (!src->render_image)
	{
		perror("Error\nNo render image\n");
		return (1);
	}
	*data = mlx_get_data_addr(src->render_image, &src->bpp,
			&src->line_len, &src->endian);
	if (!*data)
	{
		perror("Error\nFailed to get image data\n");
		return (1);
	}
	memset(*data, 0, src->width * src->height * (src->bpp / 8));
	return (0);
}

void	calc_wall_dist(t_source *src, t_raycast *ray)
{
	double	perp_wall_dist;

	(void)src;
	if (ray->side == 0)
		perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	if (perp_wall_dist < 0.0001)
		perp_wall_dist = 0.0001;
	ray->perpwalldis = perp_wall_dist;
}

void	calc_wall_projection(t_source *src, t_raycast *ray,
			int *start, int *end)
{
	int	line_height;

	line_height = (int)(src->height / ray->perpwalldis);
	*start = -line_height / 2 + src->height / 2;
	if (*start < 0)
		*start = 0;
	*end = line_height / 2 + src->height / 2;
	if (*end >= src->height)
		*end = src->height - 1;
}
