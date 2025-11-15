/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:46:59 by akahir            #+#    #+#             */
/*   Updated: 2025/11/14 19:40:01 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

int	key_events(t_source *src)
{
	double	move_speed;
	double	rot_speed;

	move_speed = src->frame_time * 1.0;
	rot_speed = src->frame_time * 0.5;
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

int	handle_close(t_source *src)
{
	ft_free_mlx(src);
	malloc_cl(0, 1);
	return (0);
}

int	ft_key_loading(int key, t_source *src)
{
	if (key == 32)
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
		src->render_image = mlx_new_image(src->mlx_pointer,
				WIDTH, HEIGHT);
		if (!src->render_image)
			return (ft_free_mlx(src), malloc_cl(0, 2), 1);
		mlx_hook(src->mlx_window, 2, (1L << 1), key_press, src);
		mlx_loop_hook(src->mlx_pointer, render_frame, src);
	}
	return (0);
}

int	ft_key_theme_b(t_source *src)
{
	int	w;
	int	h;

	w = WIDTH;
	h = HEIGHT;
	if (src->mlx_pointer)
		src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer,
				"Mandatory_Part/Parssing/texture/keyboard.xpm", &w, &h);
	if (src->mlx_image)
		mlx_put_image_to_window(src->mlx_pointer,
			src->mlx_window, src->mlx_image, 0, 0);
	else
	{
		return (perror("mlx failed"), ft_free_mlx(src),
			malloc_cl(0, 2), -1);
	}
	mlx_hook(src->mlx_window, 2, (1L << 0), ft_key_loading, src);
	return (1);
}
