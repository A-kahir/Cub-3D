/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 19:24:03 by akahir            #+#    #+#             */
/*   Updated: 2025/09/29 15:59:05 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

static void set_pixel_img(t_source *src, char *img_data, int x, int y, int color)
{
	int b_p_x;
	char *dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	b_p_x = src->bpp / 8;
	dst = img_data + (y * src->line_len + x * b_p_x);
	*(unsigned int *)dst = (unsigned int)color;
}

static void ft_frame_mini_mp(t_source *src, char *img_data, int o_x, int o_y, int mini_width, int mini_height)
{
	int i;
	int	l_r;
	int	t_b;
	int frame;

	1 && (frame = 3, l_r = 0, t_b = 0);
	while (l_r <= frame)
	{
		i = 0;
		while (i < mini_height)
		{
			set_pixel_img(src, img_data, o_x + l_r, o_y + i, 0xFFFFFF);
			set_pixel_img(src, img_data, o_x + mini_width - l_r - 1, o_y + i, 0xFFFFFF);
			i++;
		}
		l_r++;
	}
	while (t_b <= frame)
	{
		i = 0;
		while (i < mini_width)
		{
			set_pixel_img(src, img_data, o_x + i, o_y + t_b, 0xFFFFFF);
			set_pixel_img(src, img_data, o_x + i, o_y + mini_height - t_b - 1, 0xFFFFFF);
			i++;
		}
		t_b++;
	}
}

int ft_mini_map(t_source *src)
{
    int view;
    int mini_size;
    int left_off;
    int top_off;

	view = 5;
	mini_size = 15;
	left_off = 8;
	top_off = 8;
    if (!src->render_image)
        return (1);
    char *img_data = mlx_get_data_addr(src->render_image, &src->bpp, &src->line_len, &src->endian);
    if (!img_data)
        return (1);
    int start_x = (int)src->p->p_px - view - 3;
    int end_x   = (int)src->p->p_px + view + 3;
    int start_y = (int)src->p->p_py - view;
    int end_y   = (int)src->p->p_py + view;
    if (start_x < 0)
    {
        end_x -= start_x;
        start_x = 0;
    }
    if (start_y < 0)
    {
        end_y -= start_y;
        start_y = 0;
    }
    int map_row_len = ft_strlen(src->map[0]);
    int map_h = ft_lenght_j(src);
    if (end_x >= map_row_len)
    {
        start_x -= (end_x - (map_row_len - 1));
        end_x = map_row_len - 1;
    }
    if (end_y >= map_h)
    {
        start_y -= (end_y - (map_h - 1));
        end_y = map_h - 1;
    }
    if (start_x > end_x)
		start_x = 0;
    if (start_y > end_y)
		start_y = 0;
    if (start_x < 0)
		start_x = 0;
    if (start_y < 0)
		start_y = 0;
    int map_width  = (end_x - start_x + 1) * mini_size;
    int map_height = (end_y - start_y + 1) * mini_size;
    if (left_off + map_width >= WIDTH)
        map_width = WIDTH - left_off - 1;
    if (top_off + map_height >= HEIGHT)
        map_height = HEIGHT - top_off - 1;
    if (map_width <= 0 || map_height <= 0)
        return (0);
	int i = start_y;
    while (i <= end_y)
    {
		int j = start_x;
        while (j <= end_x)
        {
            int draw_x = left_off + (j - start_x) * mini_size;
            int draw_y = top_off  + (i - start_y) * mini_size;
            int color;
            if (ft_static_flag(0, 0) == 0)
            {
                if (ft_is_spaces(src->map[i][j]) == 0)
                    color = 0xB1B5B4;
                else if (src->map[i][j] == '1')
                    color = 0x000000;
                else if (src->map[i][j] == 'D')
                    color = 0xFFFFF05;
                else
                    color = 0x98B5B7;
            }
            else if (ft_static_flag(0, 0) == 1)
            {
                if (ft_is_spaces(src->map[i][j]) == 0)
                    color = 0x700000;
                else if (src->map[i][j] == '1')
                    color = 0x000000;
                else if (src->map[i][j] == 'D')
                    color = 0xFFFFF05;
                else
                    color = 0x4C4C4C;
            }
			int cy = 0;
            while (cy < mini_size)
            {
                int py = draw_y + cy;
				int cx = 0;
                while (cx < mini_size)
                {
                    int px = draw_x + cx;
                    set_pixel_img(src, img_data, px, py, color);
					cx++;
                }
				cy++;
            }
			j++;
        }
		i++;
    }
    ft_frame_mini_mp(src, img_data, left_off, top_off, map_width, map_height);
    int player_size = (mini_size / 2) + 2;
    int player_dx = left_off + (int)((src->p->p_px - start_x) * mini_size) + (mini_size - player_size) / 2;
    int player_dy = top_off  + (int)((src->p->p_py - start_y) * mini_size) + (mini_size - player_size) / 2;
	int y = 0;
    while (y < player_size)
    {
		int x = 0;
        while (x < player_size)
		{
            set_pixel_img(src, img_data, player_dx + x, player_dy + y, 0xFFFFFF);
			x++;
		}
		y++;
    }
    return (0);
}
