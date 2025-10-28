/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:46:59 by akahir            #+#    #+#             */
/*   Updated: 2025/10/28 23:44:58 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

int	mouse_move(int x, int y, t_source *src)
{
	static int	last_x;
	int			delta_x;
	double		rot_sped;

	last_x = -1;
	if (last_x == -1)
	{
		last_x = x;
		last_x = y;
	}
	delta_x = x - last_x;
	rot_sped = src->frame_time * 3.0;
	norm_mouse(src, rot_sped, delta_x);
	last_x = x;
	return (0);
}

void	key_animation(int key, t_source *src)
{
	int	h = HEIGHT;
	int	w = WIDTH / 2;

	if (key == 110)
	{
		int	i = 0;
		while (i <= 30)
		{
			char *image = ft_itoa(i);
			char *path;
			if (ft_static_flag(0, 0) == 1)
			{
				path = ft_strjoin(ft_strjoin("Bonus_Part/Parssing_b/texture/HELL/xpm_sprites/", image), ".xpm");
			}
			else
				path = ft_strjoin(ft_strjoin("Bonus_Part/Parssing_b/texture/PARADISE/xpm_sprites/", image), ".xpm");
			void *sprite = mlx_xpm_file_to_image(src->mlx_pointer, path, &w, &h);
			if (!sprite)
				return (write(2, "mlx image failed\n", 18), exit(1));
			int sp_x = (WIDTH - w) / 2;
			int sp_y = HEIGHT - h;
			mlx_put_image_to_window(src->mlx_pointer, src->mlx_window, sprite, sp_x, sp_y);
			usleep(80000);
			mlx_destroy_image(src->mlx_pointer, sprite);
			i++;
		}
	}
}

int	key_events(int key, t_source *src)
{
	double	move_speed;
	double	rot_speed;

	move_speed = src->frame_time * 5.0;
	rot_speed = src->frame_time * 3.0;
	if (key == 65307)
	{
		ft_free_mlx(src);
		malloc_cl(0, 1);
		exit(0);
	}
	norm_keys2(key, src, move_speed);
	norm_keys1(key, src, move_speed);
	norm_key_fleche(key, src, rot_speed);
	key_animation(key, src);
	norm_key3(key, src);
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
		mlx_hook(src->mlx_window, 6, 1L << 6, mouse_move, src);
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
	if (key == 49 || key == 50)
	{
		ft_secound_parsing(src);
		if (src->mlx_image)
		{
			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
			src->mlx_image = NULL;
		}
		if (key == 50)
		{
			ft_is_hell(src);
			ft_secound_parsing(src);
			ft_static_flag(1, 1);
		}
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

// int	mouse_move(int x, int y, t_source *src)
// {
// 	static int	last_x;
// 	int			delta_x;
// 	double		rot_sped;

// 	last_x = -1;
// 	if (last_x == -1)
// 	{
// 		last_x = x;
// 		last_x = y;
// 	}
// 	delta_x = x - last_x;
// 	rot_sped = src->frame_time * 3.0;
// 	norm_mouse(src, rot_sped, delta_x);
// 	last_x = x;
// 	return (0);
// }

// int	key_events(int key, t_source *src)
// {
// 	double	move_speed;
// 	double	rot_speed;

// 	move_speed = src->frame_time * 5.0;
// 	rot_speed = src->frame_time * 3.0;
// 	if (key == 53)
// 	{
// 		mlx_destroy_window(src->mlx_pointer, src->mlx_window);
// 		exit(0);
// 	}
// 	norm_keys2(key, src, move_speed);
// 	norm_keys1(key, src, move_speed);
// 	norm_key_fleche(key, src, rot_speed);
// 	return (0);
// }

// int	ft_key_loading(int key, t_source *src)
// {
// 	if (key == 36)
// 	{
// 		ft_secound_parsing(src);
// 		if (src->mlx_image)
// 		{
// 			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
// 			src->mlx_image = NULL;
// 		}
// 		mlx_clear_window(src->mlx_pointer, src->mlx_window);
// 		mlx_do_sync(src->mlx_pointer);
// 		init_player(src);
// 		init_text(src);
// 		t_doors *tmp = src->door; // debug Doors
// 		while (tmp)
// 		{
// 			printf("door => x:%d y:%d\n", tmp->x, tmp->y);
// 			tmp = tmp->next;
// 		}
// 		src->map_h = get_map_height(src->map);
// 		src->map_w = get_map_width(src->map);
// 		src->old_time = get_time();
// 		src->frame_time = 0.0;
// 		src->render_image = mlx_new_image(src->mlx_pointer,
// 				WIDTH, HEIGHT);
// 		if (!src->render_image)
// 			return (1);
// 		mlx_hook(src->mlx_window, 2, 1L << 0, key_events, src);
// 		mlx_hook(src->mlx_window, 3, 1L << 1, key_events, src);
// 		mlx_hook(src->mlx_window, 6, 1L << 6, mouse_move, src);
// 		mlx_loop_hook(src->mlx_pointer, render_frame, src);
// 	}
// 	return (0);
// }

// int	ft_key_theme_b(int key, t_source *src)
// {
// 	int	w;
// 	int	h;

// 	w = WIDTH;
// 	h = HEIGHT;
// 	if (key == 18 || key == 19)
// 	{
// 		if (src->mlx_image)
// 		{
// 			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
// 			src->mlx_image = NULL;
// 		}
// 		if (key == 19)
// 		{
// 			ft_is_hell(src);
// 			ft_static_flag(1, 1);
// 		}
// 		src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer,
// 				"Bonus_Part/Parssing_b/texture/Loading_page.xpm", &w, &h);
// 		if (src->mlx_image)
// 			mlx_put_image_to_window(src->mlx_pointer,
// 				src->mlx_window, src->mlx_image, 0, 0);
// 		else
// 			return (write(2, "mlx image failed\n", 18), exit(1), -1);
// 		mlx_key_hook(src->mlx_window, ft_key_loading, src);
// 	}
// 	return (1);
// }
