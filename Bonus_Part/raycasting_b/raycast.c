/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:24:58 by ifaleh            #+#    #+#             */
/*   Updated: 2025/10/04 17:50:49 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	init_data(t_source *src, t_raycast *ray, int *i)
{
	ray->camera_x = 2 * (*i) / (double)WIDTH - 1;
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
	if (ray->mapx < 0 || ray->mapx >= src->map_w
		|| ray->mapy < 0 || ray->mapy >= src->map_h)
		return (ray->hit = 1, 1);
	if (src->map[ray->mapy][ray->mapx] == '1')
		ray->hit = 1;
	return (0);
}

void	calculate_wall_params(t_raycast *ray, int *lineheight)
{
	if (ray->side == 0)
		ray->perpwalldis = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perpwalldis = ray->side_dist_y - ray->delta_dist_y;
	*lineheight = (int)(HEIGHT / ray->perpwalldis);
}

void	calculate_draw_limits(int lineheight,
			int *draw_start, int *draw_end)
{
	*draw_start = -lineheight / 2 + HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = lineheight / 2 + HEIGHT / 2;
	if (*draw_end >= HEIGHT)
		*draw_end = HEIGHT - 1;
}
