/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 02:11:04 by ifaleh            #+#    #+#             */
/*   Updated: 2025/09/28 20:15:28 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	norm_key_fleche(int key, t_source *src, double r_speed)
{
	double	old_d;
	double	old_p;

	if (key == 123)
	{
		old_d = src->p->dir_x;
		src->p->dir_x = src->p->dir_x * cos(-r_speed)
			- src->p->dir_y * sin(-r_speed);
		src->p->dir_y = old_d * sin(-r_speed) + src->p->dir_y * cos(-r_speed);
		old_p = src->p->plan_x;
		src->p->plan_x = old_p * cos(-r_speed) - src->p->plan_y * sin(-r_speed);
		src->p->plan_y = old_p * sin(-r_speed) + src->p->plan_y * cos(-r_speed);
	}
	if (key == 124)
	{
		old_d = src->p->dir_x;
		src->p->dir_x = old_d * cos(r_speed) - src->p->dir_y * sin(r_speed);
		src->p->dir_y = old_d * sin(r_speed) + src->p->dir_y * cos(r_speed);
		old_p = src->p->plan_x;
		src->p->plan_x = old_p * cos(r_speed) - src->p->plan_y * sin(r_speed);
		src->p->plan_y = old_p * sin(r_speed) + src->p->plan_y * cos(r_speed);
	}
}

void	norm_keys1(int key, t_source *src, double move_speed)
{
	double	newx;
	double	newy;

	if (key == 1)
	{
		newx = src->p->p_px - src->p->dir_x * move_speed;
		newy = src->p->p_py - src->p->dir_y * move_speed;
		if (newx >= 0 && newx < src->map_w && newy >= 0
			&& newy < src->map_h && src->map[(int)newy][(int)newx] != '1')
		{
			src->p->p_px = newx;
			src->p->p_py = newy;
		}
	}
	if (key == 2)
	{
		newx = src->p->p_px + src->p->plan_x * move_speed;
		newy = src->p->p_py + src->p->plan_y * move_speed;
		if (newx >= 0 && newx < src->map_w && newy >= 0 && newy < src->map_h
			&& src->map[(int)newy][(int)newx] != '1')
		{
			src->p->p_px = newx;
			src->p->p_py = newy;
		}
	}
}

void	norm_keys2(int key, t_source *src, double move_speed)
{
	double	newx;
	double	newy;

	if (key == 13)
	{
		newx = src->p->p_px + src->p->dir_x * move_speed;
		newy = src->p->p_py + src->p->dir_y * move_speed;
		if (newx >= 0 && newx < src->map_w && newy >= 0 && newy < src->map_h
			&& src->map[(int)newy][(int)newx] != '1')
		{
			src->p->p_px = newx;
			src->p->p_py = newy;
		}
	}
	if (key == 0)
	{
		newx = src->p->p_px - src->p->plan_x * move_speed;
		newy = src->p->p_py - src->p->plan_y * move_speed;
		if (newx >= 0 && newx < src->map_w && newy >= 0 && newy < src->map_h
			&& src->map[(int)newy][(int)newx] != '1')
		{
			src->p->p_px = newx;
			src->p->p_py = newy;
		}
	}
}

void	norm_mouse1(t_source *src, double rot_speed, int delta_x)
{
	double		old_d;
	double		old_p;

	old_d = src->p->dir_x;
	src->p->dir_x = old_d * cos(-rot_speed * (-delta_x) * 0.0005)
		- src->p->dir_y * sin(-rot_speed * (-delta_x) * 0.0005);
	src->p->dir_y = old_d * sin(-rot_speed * (-delta_x) * 0.0005)
		+ src->p->dir_y * cos(-rot_speed * (-delta_x) * 0.0005);
	old_p = src->p->plan_x;
	src->p->plan_x = old_p * cos(-rot_speed * (-delta_x) * 0.0005)
		- src->p->plan_y * sin(-rot_speed * (-delta_x) * 0.0005);
	src->p->plan_y = old_p * sin(-rot_speed * (-delta_x) * 0.0005)
		+ src->p->plan_y * cos(-rot_speed * (-delta_x) * 0.0005);
}

void	norm_mouse(t_source *src, double rot_speed, int delta_x)
{
	double		old_d;
	double		old_p;

	if (delta_x > 0)
	{
		old_d = src->p->dir_x;
		src->p->dir_x = old_d * cos(rot_speed * delta_x * 0.0005)
			- src->p->dir_y * sin(rot_speed * delta_x * 0.0005);
		src->p->dir_y = old_d * sin(rot_speed * delta_x * 0.0005)
			+ src->p->dir_y * cos(rot_speed * delta_x * 0.0005);
		old_p = src->p->plan_x;
		src->p->plan_x = old_p * cos(rot_speed * delta_x * 0.0005)
			- src->p->plan_y * sin(rot_speed * delta_x * 0.0005);
		src->p->plan_y = old_p * sin(rot_speed * delta_x * 0.0005)
			+ src->p->plan_y * cos(rot_speed * delta_x * 0.0005);
	}
	else if (delta_x < 0)
		norm_mouse1(src, rot_speed, delta_x);
}

