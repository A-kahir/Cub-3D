/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:03:45 by akahir            #+#    #+#             */
/*   Updated: 2025/09/12 18:39:20 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	ft_mini_map(t_source *src)
{
    int view = 5;
	int start_x = src->player->player_px - view - 4;
	int end_x = src->player->player_px + view + 4;
	
	int start_y = src->player->player_py - view;
	int end_y = src->player->player_py + view;
	
	if (start_x < 0)
		start_x = 0;
	if (start_y < 0)
		start_y = 0;
	if (end_x >= ft_strlen(src->map[0]))
		end_x = ft_strlen(src->map[0]) - 1;
	if (end_y >= ft_lenght_j(src))
		end_y = ft_lenght_j(src);
	
	int i = start_y;
	int mini_size;
	while (i <= end_y)
	{
		int j = start_x;
		while (j <= end_x)
		{
			mini_size = 15;
			int draw_x = (j - start_x) * mini_size;
			int draw_y = (i - start_y) * mini_size;

			int t_y = 0;
			while (t_y < mini_size)
			{
				int t_x = 0;
				while (t_x < mini_size)
				{
					if (src->map[i][j] == '1')
						mlx_pixel_put(src->mlx_pointer, src->mlx_window, (draw_x + t_x + 8), (draw_y + t_y + 8), 0x000000);
					else if (src->map[i][j] == '0')
						mlx_pixel_put(src->mlx_pointer, src->mlx_window, (draw_x + t_x + 8), (draw_y + t_y + 8), 0x2084847F);
					else
						mlx_pixel_put(src->mlx_pointer, src->mlx_window, (draw_x + t_x + 8), (draw_y + t_y + 8), 0x7084847F);
					t_x++;
				}
				t_y++;
			}
			j++;
		}
		i++;
	}
	
	int mini_height = (end_y - start_y) * mini_size + 15;
	int mini_width = (end_x - start_x + 1) * mini_size;
	int frame_stroke = 3;
	
	int l_r = 0;
	while (l_r <= frame_stroke)
	{
		i = 0;
		while (i < mini_height)
		{
			mlx_pixel_put(src->mlx_pointer, src->mlx_window, 8 + l_r, 8 + i, 0xDCDCDC);
			mlx_pixel_put(src->mlx_pointer, src->mlx_window, 8 + mini_width - l_r, 8 + i, 0xDCDCDC);
			i++;
		}
		l_r++;
	}

	int t_b = 0;
	while (t_b <= frame_stroke)
	{
		i = 0;
		while (i < mini_width)
		{
			mlx_pixel_put(src->mlx_pointer, src->mlx_window, 8 + i, 8 + t_b, 0xDCDCDC);
			mlx_pixel_put(src->mlx_pointer, src->mlx_window, 8 + i, 8 + mini_height - t_b, 0xDCDCDC);
			i++;
		}
		t_b++;
	}


	
	int player_dx = (src->player->player_px - start_x) * mini_size;
	int player_dy = (src->player->player_py - start_y) * mini_size;
	int y = 0;
	while (y < mini_size)
	{
		int x = 0;
		while (x < mini_size)
		{
			mlx_pixel_put(src->mlx_pointer, src->mlx_window, (player_dx + x + 8), (player_dy + y + 8), 0xFF0000); // player (Red);
			x++;
		}
		y++;
	}
}
