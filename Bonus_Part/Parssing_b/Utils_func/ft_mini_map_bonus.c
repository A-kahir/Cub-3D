/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:41:40 by akahir            #+#    #+#             */
/*   Updated: 2025/10/29 20:36:23 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

static void ft_frame_mini_mp2(t_source *src, char *img_data, int o_x, int o_y)
{
    int i;
    int	t_b;

    t_b = 0;
    while (t_b <= 3)
	{
		i = 0;
		while (i < src->mmp->map_width)
		{
			ft_set_pixel_img(src, img_data, o_x + i, o_y + t_b, 0xFFFFFF);
			ft_set_pixel_img(src, img_data, o_x + i, o_y + src->mmp->map_height - t_b - 1, 0xFFFFFF);
			i++;
		}
		t_b++;
	}
}

static void ft_frame_mini_mp(t_source *src, char *img_data, int o_x, int o_y)
{
	int i;
	int	l_r;

	l_r = 0;
	while (l_r <= 3)
	{
		i = 0;
		while (i < src->mmp->map_height)
		{
			ft_set_pixel_img(src, img_data, o_x + l_r, o_y + i, 0xFFFFFF);
			ft_set_pixel_img(src, img_data, o_x + src->mmp->map_width - l_r - 1, o_y + i, 0xFFFFFF);
			i++;
		}
		l_r++;
	}
    ft_frame_mini_mp2(src, img_data, o_x, o_y);
}

int ft_get_color_pixel(t_source *src, int i, int j)
{
    int color = 0;

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
    return (color);
}

static void ft_draw_player(t_source *src, char *img_data, t_minimp *mmp)
{
    int player_size;
    int player_dx;
    int player_dy;
    int y;
    int x;

    player_size = (mmp->mini_size / 2) + 2;
    player_dx = 8 + (src->p->p_px - mmp->start_x) * mmp->mini_size - player_size / 2;
    player_dy = 8 + (src->p->p_py - mmp->start_y) * mmp->mini_size - player_size / 2;
    y = 0;
    while (y < player_size)
    {
        x = 0;
        while (x < player_size)
        {
            ft_set_pixel_img(src, img_data, player_dx + x, player_dy + y, 0xFFFFFF);
            x++;
        }
        y++;
    }
}

int ft_mini_map(t_source *src)
{
    char *img_data;
    t_minimp mmp;
    int map_row_len;
    int map_h;

    if (!src->render_image)
        return (1);
    img_data = mlx_get_data_addr(src->render_image, &src->bpp, &src->line_len, &src->endian);
    if (!img_data)
        return (1);
    src->mmp = malloc_cl(sizeof(t_minimp), 0);
    if (!src->mmp)
        return (-1);
    ft_init_minimap(&mmp, src);
    map_row_len = ft_strlen(src->map[0]);
    map_h = ft_lenght_j(src);
    ft_cadring_outside(&mmp, map_row_len, map_h);
    ft_fix_negative(&mmp);
    ft_calc_demonsions(&mmp);
    if (mmp.map_width <= 0 || mmp.map_height <= 0)
        return (0);
    *src->mmp = mmp;
    ft_render_tiles(src, img_data, src->mmp);
    ft_frame_mini_mp(src, img_data, 8, 8);
    return (ft_draw_player(src, img_data, src->mmp), 0);
}
