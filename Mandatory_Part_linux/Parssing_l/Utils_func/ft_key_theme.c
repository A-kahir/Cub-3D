/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:46:59 by akahir            #+#    #+#             */
/*   Updated: 2025/09/20 18:10:14 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

int	key_events(int key, t_source *src)
{
	double	move_speed;
	double	rot_speed;
	double	old_dirX;
	double	old_plan_x;
	double newX;
	double newY;

	move_speed = src->frame_time * 5.0;
	rot_speed = src->frame_time * 3.0;
	if (key == 65307)
	{
		mlx_destroy_window(src->mlx_pointer, src->mlx_window);
		exit(0);
	}
	if (key == 119)
	{
		newX = src->player->player_px + src->player->dir_x * move_speed;
		newY = src->player->player_py + src->player->dir_y * move_speed;
		if (newX >= 0 && newX < src->map_w && newY >= 0 && newY < src->map_h && src->map[(int)newY][(int)newX] != '1')
		{
			src->player->player_px = newX;
			src->player->player_py = newY;
		}
		if (src->map[(int)src->player->player_py - 1][(int)src->player->player_px] != '1')
			src->player->player_py--;
	}
	if (key == 97)
	{
		newX = src->player->player_px - src->player->plan_x * move_speed;
		newY = src->player->player_py - src->player->plan_y * move_speed;
		if (newX >= 0 && newX < src->map_w && newY >= 0 && newY < src->map_h && src->map[(int)newY][(int)newX] != '1')
		{
			src->player->player_px = newX;
			src->player->player_py = newY;
		}
		if (src->map[(int)src->player->player_py][(int)src->player->player_px - 1] != '1')
			src->player->player_px--;
	}
	if (key == 115)
	{
		newX = src->player->player_px - src->player->dir_x * move_speed;
		newY = src->player->player_py - src->player->dir_y * move_speed;
		if (newX >= 0 && newX < src->map_w && newY >= 0 && newY < src->map_h && src->map[(int)newY][(int)newX] != '1')
		{
			src->player->player_px = newX;
			src->player->player_py = newY;
		}
		if (src->map[(int)src->player->player_py + 1][(int)src->player->player_px] != '1')
			src->player->player_py++;
	}
	if (key == 100)
	{
		newX = src->player->player_px + src->player->plan_x * move_speed;
		newY = src->player->player_py + src->player->plan_y * move_speed;
		if (newX >= 0 && newX < src->map_w && newY >= 0 && newY < src->map_h && src->map[(int)newY][(int)newX] != '1')
		{
			src->player->player_px = newX;
			src->player->player_py = newY;
		}
		if (src->map[(int)src->player->player_py][(int)src->player->player_px - 1] != '1')
			src->player->player_px++;
	}
	if (key == 65361)
	{
		old_dirX = src->player->dir_x;
		src->player->dir_x = src->player->dir_x * cos(-rot_speed) - src->player->dir_y * sin(-rot_speed);
		src->player->dir_y = old_dirX * sin(-rot_speed) + src->player->dir_y * cos(-rot_speed);
		old_plan_x = src->player->plan_x;
		src->player->plan_x = src->player->plan_x * cos(-rot_speed) - src->player->plan_y * sin(-rot_speed);
		src->player->plan_y = old_plan_x * sin(-rot_speed) + src->player->plan_y * cos(-rot_speed);
	}
	if (key == 65363)
	{
		old_dirX = src->player->dir_x;
		src->player->dir_x = src->player->dir_x * cos(rot_speed) - src->player->dir_y * sin(rot_speed);
		src->player->dir_y = old_dirX * sin(rot_speed) + src->player->dir_y * cos(rot_speed);
		old_plan_x = src->player->plan_x;
		src->player->plan_x = src->player->plan_x * cos(rot_speed) - src->player->plan_y * sin(rot_speed);
		src->player->plan_y = old_plan_x * sin(rot_speed) + src->player->plan_y * cos(rot_speed);
	}
	// mlx_key_hook(src->mlx_window, ft_key_move_player, src);
	// ft_mini_map(src);
	return (0);
}

int	ft_key_loading(int key, t_source *src)
{
	if (key == 65293)
	{
		ft_secound_parsing(src);
		if (src->mlx_image)
		{
			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
			src->mlx_image = NULL;
		}
		mlx_clear_window(src->mlx_pointer, src->mlx_window);
        mlx_do_sync(src->mlx_pointer);
		printf("==> now you will start game\n**************************\n");
		init_player(src);
		init_text(src);
		// ft_debug(src, 2);
		src->old_time = get_time();
		src->frame_time = 0.0;
		src->render_image = mlx_new_image(src->mlx_pointer, src->width, src->height);
		if (!src->render_image)
			return (0);
		mlx_key_hook(src->mlx_window, key_events, src);
		mlx_loop_hook(src->mlx_pointer, render_frame, src);
		// ft_mini_map(src);
		// mlx_loop_hook(src->mlx_pointer, ft_mini_map, src); //bonus Part
	// 	mlx_key_hook(src->mlx_window, ft_key_move_player, src); // Bonus Part
	 }
	return (-1);
}

int	ft_key_theme(int key, t_source *src)
{
	int	w;
	int	h;

	w = src->width;
	h = src->height;
	if (key == 49 || key == 50)
	{
		if (src->mlx_image)
		{
			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
			src->mlx_image = NULL;
		}
		if (key == 50)
			ft_is_hell(src);
		src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer,
				"Parssing_l/texture/Loading_page.xpm", &w, &h);
		if (src->mlx_image)
			mlx_put_image_to_window(src->mlx_pointer,
				src->mlx_window, src->mlx_image, 0, 0);
		else
			return (write(2, "mlx image failed\n", 18), exit(1), -1);
		mlx_key_hook(src->mlx_window, ft_key_loading, src);
		return (1);
	}
	return (-1);
}
