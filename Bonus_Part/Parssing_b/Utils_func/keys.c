/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 02:11:04 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/10 18:19:36 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	norm_key_fleche(t_source *src, double r_speed)
{
	double	old_d;
	double	old_p;

	if (src->keys.left)
	{
		old_d = src->p->dir_x;
		src->p->dir_x = src->p->dir_x * cos(-r_speed)
			- src->p->dir_y * sin(-r_speed);
		src->p->dir_y = old_d * sin(-r_speed) + src->p->dir_y * cos(-r_speed);
		old_p = src->p->plan_x;
		src->p->plan_x = old_p * cos(-r_speed) - src->p->plan_y * sin(-r_speed);
		src->p->plan_y = old_p * sin(-r_speed) + src->p->plan_y * cos(-r_speed);
	}
	if (src->keys.right)
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
	int		door_id;

	if (x < 0 || x >= src->map_w || y < 0 || y >= src->map_h)
		return (0);
	col = src->map[y][x];
	if (col == '1')
		return (0);
	if (col == 'D')
	{
		door_id = ft_door(src, x, y);
		if (door_id == -1)
			return (0);
		return (door_state(src, door_id) == 0);
	}
	return (1);
}

void	norm_keys2(t_source *src, double move_speed)
{
	double	newx;
	double	newy;

	if (src->keys.w)
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
	if (src->keys.a)
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

void	norm_keys1(t_source *src, double move_speed)
{
	double	newx;
	double	newy;

	if (src->keys.s)
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
	if (src->keys.d)
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

void	norm_key3(int key, t_source *src)
{
	double		dest;
	t_doors		*current;

	current = src->door;
	if (key == 32)
	{
		while (current)
		{
			dest = sqrt(pow(src->p->p_px - current->x, 2)
					+ pow(src->p->p_py - current->y, 2));
			if (dest < 1.5)
				current->etat = !current->etat;
			current = current->next;
		}
	}
}
