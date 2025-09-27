/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:46:59 by akahir            #+#    #+#             */
/*   Updated: 2025/09/27 20:04:20 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

int	key_events(int key, t_source *src)
{
	double	move_speed;
	double	rot_speed;

	move_speed = src->frame_time * 5.0;
	rot_speed = src->frame_time * 3.0;
	if (key == 53)
	{
		mlx_destroy_window(src->mlx_pointer, src->mlx_window);
		exit(0);
	}
	norm_keys2(key, src, move_speed);
	norm_keys1(key, src, move_speed);
	norm_key_fleche(key, src, rot_speed);
	return (0);
}

int	ft_key_loading(int key, t_source *src)
{
	if (key == 36)
	{
		ft_secound_parsing(src);
		if (src->mlx_image)
		{
			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
			src->mlx_image = NULL;
		}
		mlx_clear_window(src->mlx_pointer, src->mlx_window);
		mlx_do_sync(src->mlx_pointer);
		init_player(src);
		init_text(src);
		src->map_h = get_map_height(src->map);
		src->map_w = get_map_width(src->map);
		src->old_time = get_time();
		src->frame_time = 0.0;
		src->render_image = mlx_new_image(src->mlx_pointer,
				WIDTH, HEIGHT);
		if (!src->render_image)
			return (1);
		mlx_hook(src->mlx_window, 2, 1L << 0, key_events, src);
		mlx_hook(src->mlx_window, 3, 1L << 1, key_events, src);
		mlx_loop_hook(src->mlx_pointer, render_frame, src);
	}
	return (0);
}

int	ft_key_theme_b(int key, t_source *src)
{
	int	w;
	int	h;

	w = WIDTH;
	h = HEIGHT;
	if (key == 18 || key == 19)
	{
		if (src->mlx_image)
		{
			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
			src->mlx_image = NULL;
		}
		if (key == 19)
			ft_is_hell(src);
		src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer,
				"Bonus_Part/Parssing_b/texture/Loading_page.xpm", &w, &h);
		if (src->mlx_image)
			mlx_put_image_to_window(src->mlx_pointer,
				src->mlx_window, src->mlx_image, 0, 0);
		else
			return (write(2, "mlx image failed\n", 18), exit(1), -1);
		mlx_key_hook(src->mlx_window, ft_key_loading, src);
	}
	return (1);
}
