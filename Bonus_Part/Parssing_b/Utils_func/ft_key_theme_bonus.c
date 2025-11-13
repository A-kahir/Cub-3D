/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:46:59 by akahir            #+#    #+#             */
/*   Updated: 2025/11/11 18:10:28 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

int	mouse_move(int x, int y, t_source *src)
{
	int			delta_x;
	double		rot_speed;

	(void) y;
	if (src->mouse_last_x == -1)
	{
		src->mouse_last_x = x;
		return (0);
	}
	delta_x = x - src->mouse_last_x;
	if (delta_x == 0)
	{
		src->mouse_last_x = x;
		return (0);
	}
	rot_speed = src->frame_time * 3.0;
	norm_mouse(src, rot_speed, delta_x);
	src->mouse_last_x = x;
	return (0);
}

int	key_events(t_source *src)
{
	double	move_speed;
	double	rot_speed;

	move_speed = src->frame_time * 5.0;
	rot_speed = src->frame_time * 3.0;
	if (src->keys.esc)
	{
		ft_free_mlx(src);
		malloc_cl(0, 1);
		exit(0);
	}
	if (src->keys.a || src->keys.w)
		norm_keys2(src, move_speed);
	if (src->keys.s || src->keys.d)
		norm_keys1(src, move_speed);
	if (src->keys.right || src->keys.left)
		norm_key_fleche(src, rot_speed);
	return (0);
}

int	ft_key_loading(int key, t_source *src)
{
	if (key == 65293)
	{
		if (src->mlx_image)
		{
			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
			src->mlx_image = NULL;
		}
		mlx_clear_window(src->mlx_pointer, src->mlx_window);
		init_player(src);
		init_text(src);
		src->map_h = get_map_height(src->map);
		src->map_w = get_map_width(src->map);
		src->old_time = get_time();
		if (src->old_time == -1)
			return (ft_free_mlx(src), malloc_cl(0, 2), -1);
		src->frame_time = 0.0;
		init_keys(src);
		src->render_image = mlx_new_image(src->mlx_pointer,
				WIDTH, HEIGHT);
		if (!src->render_image)
			return (1);
		mlx_hook(src->mlx_window, 2, (1L << 1), key_press, src);
		mlx_loop_hook(src->mlx_pointer, render_frame, src);
	}
	return (0);
}

int	ft_key_theme_b(int key, t_source *src)
{
	int	w;
	int	h;

	1 && (w = WIDTH, h = HEIGHT);
	if (key == 49 || key == 50)
	{
		ft_sec_parsing(src);
		if (src->mlx_image)
		{
			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
			src->mlx_image = NULL;
		}
		if (key == 50)
			1 && (ft_is_hell(src), ft_sec_parsing(src), ft_static_flag(1, 1));
		src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer,
				"Bonus_Part/Parssing_b/texture/Loading_page.xpm", &w, &h);
		if (src->mlx_image)
			mlx_put_image_to_window(src->mlx_pointer,
				src->mlx_window, src->mlx_image, 0, 0);
		else
			(write(2, "mlx image failed\n", 18),
				ft_free_mlx(src), malloc_cl(0, 2));
		mlx_hook(src->mlx_window, 2, (1L << 0), ft_key_loading, src);
	}
	return (1);
}
