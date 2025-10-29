/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixels_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:29:18 by akahir            #+#    #+#             */
/*   Updated: 2025/10/29 16:31:22 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void ft_set_pixel_img(t_source *src, char *img_data, int x, int y, int color)
{
	int b_p_x;
	char *dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	b_p_x = src->bpp / 8;
	dst = img_data + (y * src->line_len + x * b_p_x);
	*(unsigned int *)dst = (unsigned int)color;
}

void ft_draw_pixel(t_source *src, char *img_data, t_minimp *mmp, int color)
{
    int cy;
    int cx;
    int px;
    int py;

    cy = 0;
    while (cy < mmp->mini_size)
    {
        py = mmp->top_off + cy;
        cx = 0;
        while (cx < mmp->mini_size)
        {
            px = mmp->left_off + cx;
            ft_set_pixel_img(src, img_data, px, py, color);
            cx++;
        }
        cy++;
    }
}

void ft_render_tiles(t_source *src, char *img_data, t_minimp *mmp)
{
    int i;
    int j;
    int color;

    i = mmp->start_y;
    while (i <= mmp->end_y)
    {
        j = mmp->start_x;
        while (j <= mmp->end_x)
        {
            mmp->left_off = 8 + (j - mmp->start_x) * mmp->mini_size;
            mmp->top_off = 8 + (i - mmp->start_y) * mmp->mini_size;
            color = ft_get_color_pixel(src, i, j);
            ft_draw_pixel(src, img_data, mmp, color);
            j++;
        }
        i++;
    }
}
