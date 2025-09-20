/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:37:31 by akahir            #+#    #+#             */
/*   Updated: 2025/09/19 18:28:56 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

int ft_key_move_player(int key, t_source *src)
{
	if (key == 13 || key == 1 || key == 0 || key == 2)
	{
		if (key == 13) // W
		{
			if (src->map[src->player->player_py - 1][src->player->player_px] != '1')
				src->player->player_py--;
		}
		else if (key == 1) // S
		{
			if (src->map[src->player->player_py + 1][src->player->player_px] != '1')
				src->player->player_py++;
		}
		else if (key == 0) // A
		{
			if (src->map[src->player->player_py][src->player->player_px - 1] != '1')
				src->player->player_px--;
		}
		else if (key == 2) // D
		{
			if (src->map[src->player->player_py][src->player->player_px + 1] != '1')
				src->player->player_px++;
		}
		ft_mini_map(src);
	}
    return (0);
}

void ft_put_frame_minimap(t_source *src, int mini_width, int mini_height)
{
    int	i;
	int	l_r;
	int	t_b;
    int frame_stroke;

	frame_stroke = 3;
    l_r = 0;
    while (l_r <= frame_stroke)
    {
        i = 0;
        while (i < mini_height)
        {
            mlx_pixel_put(src->mlx_pointer, src->mlx_window, 8 + l_r, 8 + i, 0xFFFFFF);
            mlx_pixel_put(src->mlx_pointer, src->mlx_window, 8 + mini_width - l_r, 8 + i, 0xFFFFFF);
            i++;
        }
        l_r++;
    }
    t_b = 0;
    while (t_b <= frame_stroke)
    {
        i = 0;
        while (i < mini_width)
        {
            mlx_pixel_put(src->mlx_pointer, src->mlx_window, 8 + i, 8 + t_b, 0xFFFFFF);
            mlx_pixel_put(src->mlx_pointer, src->mlx_window, 8 + i, 8 + mini_height - t_b, 0xFFFFFF);
            i++;
        }
        t_b++;
    }
}


void	ft_mini_map(t_source *src)
{
    int view = 5;
	int mini_size = 15;
	int start_x = src->player->player_px - view - 3;
	int end_x = src->player->player_px + view + 3;
	
	int start_y = src->player->player_py - view;
	int end_y = src->player->player_py + view;

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
	if (end_x >= ft_strlen(src->map[0]))
	{
		start_x -= (end_x - (ft_strlen(src->map[0]) - 1));
		end_x = ft_strlen(src->map[0]) - 1;
	}
	if (end_y >= ft_lenght_j(src))
	{
		start_y -= (end_y - ft_lenght_j(src));
		end_y = ft_lenght_j(src);
	}
	
	if (start_x > end_x)
    	start_x = 0;
	if (start_y > end_y)
		start_y = 0;
	
	if (start_x < 0)
		start_x = 0;
	if (start_y < 0)
		start_y = 0;

	int i = start_y;
	while (i <= end_y)
	{
		int j = start_x;
		while (j <= end_x)
		{
			int draw_x = (j - start_x) * mini_size;
			int draw_y = (i - start_y) * mini_size;

			int t_y = 0;
			while (t_y < mini_size)
			{
				int t_x = 0;
				while (t_x < mini_size)
				{
					if (ft_is_spaces(src->map[i][j]) == 0)
						mlx_pixel_put(src->mlx_pointer, src->mlx_window, (draw_x + t_x + 8), (draw_y + t_y + 8), 0xB1B5B4);
					else if (src->map[i][j] == '1')
						mlx_pixel_put(src->mlx_pointer, src->mlx_window, (draw_x + t_x + 8), (draw_y + t_y + 8), 0x000000);
					else if (src->map[i][j] == '0' || src->map[i][j] == 'N'
						|| src->map[i][j] == 'S' || src->map[i][j] == 'W' || src->map[i][j] == 'E')
						mlx_pixel_put(src->mlx_pointer, src->mlx_window, (draw_x + t_x + 8), (draw_y + t_y + 8), 0x98B5B7);
					t_x++;
				}
				t_y++;
			}
			j++;
		}
		i++;
	}

	int map_width  = (end_x - start_x + 1) * mini_size;
	int map_height = (end_y - start_y + 1) * mini_size;
	if (start_x < 0)
		start_x = 0;
	if (start_y < 0)
		start_y = 0;
	if (end_x >= map_width)
		end_x = map_width - 1;
	if (end_y >= map_height)
		end_y = map_height - 1;
	ft_put_frame_minimap(src ,map_width, map_height);
	
	int player_size = (mini_size / 2) + 2;
	int player_dx = (src->player->player_px - start_x) * mini_size + player_size / 2;
	int player_dy = (src->player->player_py - start_y) * mini_size + player_size / 2;
	int y = 0;
	while (y < player_size)
	{
		int x = 0;
		while (x < player_size)
		{
			mlx_pixel_put(src->mlx_pointer, src->mlx_window, (player_dx + x + 8), (player_dy + y + 8), 0xFFFFFF);
			x++;
		}
		y++;
	}
}
