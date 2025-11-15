/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixels_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:56:37 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/14 22:41:41 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	ft_set_pixel_img(t_source *src, char *img_data, t_pixel pix, int color)
{
	int		b_p_x;
	char	*dst;

	if (pix.x < 0 || pix.y < 0 || pix.x >= WIDTH || pix.y >= HEIGHT)
		return ;
	b_p_x = src->bpp / 8;
	dst = img_data + (pix.y * src->line_len + pix.x * b_p_x);
	*(unsigned int *)dst = (unsigned int)color;
}

void	ft_draw_pixel(t_source *src, char *img_data, t_minimp *mmp, int color)
{
	int		cy;
	int		cx;
	t_pixel	pixel;

	cy = 0;
	while (cy < mmp->mini_size)
	{
		pixel.y = mmp->top_off + cy;
		cx = 0;
		while (cx < mmp->mini_size)
		{
			pixel.x = mmp->left_off + cx;
			ft_set_pixel_img(src, img_data, pixel, color);
			cx++;
		}
		cy++;
	}
}

void	ft_render_tiles(t_source *src, char *img_data, t_minimp *mmp)
{
	int	i;
	int	j;
	int	color;

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
