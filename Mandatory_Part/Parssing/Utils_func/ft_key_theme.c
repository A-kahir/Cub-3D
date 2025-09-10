/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:46:59 by akahir            #+#    #+#             */
/*   Updated: 2025/09/10 17:38:19 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	init_player(t_source *src)
{
	src->player->player_px = src->player->player_px + 0.5;
	src->player->player_py = src->player->player_or + 0.5;
	if (src->player->player_or == 'N')
	{
		src->player->dir_x = 0;
		src->player->dir_y = -1;
		src->player->plan_x = 0.66;
		src->player->plan_y = 0;
	}
	if (src->player->player_or == 'S')
	{
		src->player->dir_x = 0;
		src->player->dir_y = 1;
		src->player->plan_x = -0.66;
		src->player->plan_y = 0;
	}
	if (src->player->player_or == 'E')
	{
		src->player->dir_x = 1;
		src->player->dir_y = 0;
		src->player->plan_x = 0;
		src->player->plan_y = 0.66;
	}
	if (src->player->player_or == 'W')
	{
		src->player->dir_x = -1;
		src->player->dir_y = 0;
		src->player->plan_x = 0;
		src->player->plan_y = -0.66;
	}
}
int	key_events(int key, t_source *src)
{
	if (key == 53)
	{
		mlx_destroy_window(src->mlx_pointer, src->mlx_window);
		exit(0);
	}
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
		printf("==> now you will start game\n**************************\n");
		init_player(src);
		// ft_debug(src, 2);
		// printf("Colors: C=%x, F=%x\n", src->colors->hexa_rgb_c, src->colors->hexa_rgb_f);
		src->render_image = mlx_new_image(src->mlx_pointer, src->width, src->height);
		if (!src->render_image)
			return (0);
		mlx_get_data_addr(src->render_image, &src->bpp, &src->line_len, &src->endian);
		mlx_loop_hook(src->mlx_pointer, render_frame, src);
		mlx_key_hook(src->mlx_window, key_events, src);
	}
	return (0);
}

int	ft_key_theme(int key, t_source *src)
{
	int	w;
	int	h;

	w = src->width;
	h = src->height;
	if (key == 19 || key == 18)
	{
		if (src->mlx_image)
		{
			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
			src->mlx_image = NULL;
		}
		if (key == 19)
			ft_is_hell(src);
		src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer,
				"Parssing/texture/Loading_page.xpm", &w, &h);
		if (src->mlx_image)
			mlx_put_image_to_window(src->mlx_pointer,
				src->mlx_window, src->mlx_image, 0, 0);
		else
			return (write(2, "mlx image failed\n", 18), -1);
		return (mlx_key_hook(src->mlx_window, ft_key_loading, src), 1);
	}
	return (-1);
}
