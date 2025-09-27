/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:11:18 by ifaleh            #+#    #+#             */
/*   Updated: 2025/09/27 08:25:08 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	init_n_s(t_source *src)
{
	if (src->p->p_or == 'N')
	{
		src->p->dir_x = 0;
		src->p->dir_y = -1;
		src->p->plan_x = 0.66;
		src->p->plan_y = 0;
	}
	if (src->p->p_or == 'S')
	{
		src->p->dir_x = 0;
		src->p->dir_y = 1;
		src->p->plan_x = -0.66;
		src->p->plan_y = 0;
	}
}

void	init_e_w(t_source *src)
{
	if (src->p->p_or == 'E')
	{
		src->p->dir_x = 1;
		src->p->dir_y = 0;
		src->p->plan_x = 0;
		src->p->plan_y = 0.66;
	}
	if (src->p->p_or == 'W')
	{
		src->p->dir_x = -1;
		src->p->dir_y = 0;
		src->p->plan_x = 0;
		src->p->plan_y = -0.66;
	}
}

void	init_player(t_source *src)
{
	src->p->p_px += 0.5;
	src->p->p_py += 0.5;
	init_n_s(src);
	init_e_w(src);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}