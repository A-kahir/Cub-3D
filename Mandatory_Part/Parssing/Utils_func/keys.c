/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 02:11:04 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/03 22:54:22 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

void	norm_key_fleche(int key, t_source *src, double r_speed)
{
	double	old_d;
	double	old_p;

	if (key == 65361)
	{
		old_d = src->p->dir_x;
		src->p->dir_x = src->p->dir_x * cos(-r_speed)
			- src->p->dir_y * sin(-r_speed);
		src->p->dir_y = old_d * sin(-r_speed) + src->p->dir_y * cos(-r_speed);
		old_p = src->p->plan_x;
		src->p->plan_x = old_p * cos(-r_speed) - src->p->plan_y * sin(-r_speed);
		src->p->plan_y = old_p * sin(-r_speed) + src->p->plan_y * cos(-r_speed);
	}
	if (key == 65363)
	{
		old_d = src->p->dir_x;
		src->p->dir_x = old_d * cos(r_speed) - src->p->dir_y * sin(r_speed);
		src->p->dir_y = old_d * sin(r_speed) + src->p->dir_y * cos(r_speed);
		old_p = src->p->plan_x;
		src->p->plan_x = old_p * cos(r_speed) - src->p->plan_y * sin(r_speed);
		src->p->plan_y = old_p * sin(r_speed) + src->p->plan_y * cos(r_speed);
	}
}

int	can_pass(t_source *src, int x, int y)
{
	char	col;

	if (x < 0 || x >= src->map_w || y < 0 || y >= src->map_h)
		return (0);
	col = src->map[y][x];
	if (col == '1')
		return (0);
	return (1);
}

void	norm_keys2(int key, t_source *src, double move_speed)
{
	double	newx;
	double	newy;

	if (key == 119)
	{
		newx = src->p->p_px + src->p->dir_x * move_speed;
		newy = src->p->p_py + src->p->dir_y * move_speed;
		if (can_pass(src, (int)newx, (int)src->p->p_py)
			&& can_pass(src, (int)src->p->p_px, (int)newy))
		{
			src->p->p_px = newx;
			src->p->p_py = newy;
		}
	}
	if (key == 97)
	{
		newx = src->p->p_px - src->p->plan_x * move_speed;
		newy = src->p->p_py - src->p->plan_y * move_speed;
		if (can_pass(src, (int)newx, (int)src->p->p_py)
			&& can_pass(src, (int)src->p->p_px, (int)newy))
		{
			src->p->p_px = newx;
			src->p->p_py = newy;
		}
	}
}

void	norm_keys1(int key, t_source *src, double move_speed)
{
	double	newx;
	double	newy;

	if (key == 115)
	{
		newx = src->p->p_px - src->p->dir_x * move_speed;
		newy = src->p->p_py - src->p->dir_y * move_speed;
		if (can_pass(src, (int)newx, (int)src->p->p_py)
			&& can_pass(src, (int)src->p->p_px, (int)newy))
		{
			src->p->p_px = newx;
			src->p->p_py = newy;
		}
	}
	if (key == 100)
	{
		newx = src->p->p_px + src->p->plan_x * move_speed;
		newy = src->p->p_py + src->p->plan_y * move_speed;
		if (can_pass(src, (int)newx, (int)src->p->p_py)
			&& can_pass(src, (int)src->p->p_px, (int)newy))
		{
			src->p->p_px = newx;
			src->p->p_py = newy;
		}
	}
}
