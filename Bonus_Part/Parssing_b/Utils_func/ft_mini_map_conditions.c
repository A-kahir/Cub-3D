/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map_conditions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:55:14 by ifaleh            #+#    #+#             */
/*   Updated: 2025/10/29 22:36:27 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	ft_init_minimap(t_minimp *mmp, t_source *src)
{
	mmp->view = 5;
	mmp->mini_size = 15;
	mmp->left_off = 8;
	mmp->top_off = 8;
	mmp->start_x = (int)src->p->p_px - mmp->view - 3;
	mmp->end_x = (int)src->p->p_px + mmp->view + 3;
	mmp->start_y = (int)src->p->p_py - mmp->view;
	mmp->end_y = (int)src->p->p_py + mmp->view;
}

void	ft_cadring_outside(t_minimp *mmp, int map_w, int map_h)
{
	if (mmp->start_x < 0)
	{
		mmp->end_x -= mmp->start_x;
		mmp->start_x = 0;
	}
	if (mmp->start_y < 0)
	{
		mmp->end_y -= mmp->start_y;
		mmp->start_y = 0;
	}
	if (mmp->end_x >= map_w)
	{
		mmp->start_x -= (mmp->end_x - (map_w));
		mmp->end_x = map_w;
	}
	if (mmp->end_y >= map_h)
	{
		mmp->start_y -= (mmp->end_y - (map_h));
		mmp->end_y = map_h;
	}
}

void	ft_fix_negative(t_minimp *mmp)
{
	if (mmp->start_x > mmp->end_x || mmp->start_x < 0)
		mmp->start_x = 0;
	if (mmp->start_y > mmp->end_y || mmp->start_y < 0)
		mmp->start_y = 0;
}

void	ft_calc_demonsions(t_minimp *mmp)
{
	mmp->map_width = (mmp->end_x - mmp->start_x + 1) * mmp->mini_size;
	mmp->map_height = (mmp->end_y - mmp->start_y + 1) * mmp->mini_size;
	if (mmp->left_off + mmp->map_width >= WIDTH)
		mmp->map_width = WIDTH - mmp->left_off - 1;
	if (mmp->top_off + mmp->map_height >= HEIGHT)
		mmp->map_height = HEIGHT - mmp->top_off - 1;
}
