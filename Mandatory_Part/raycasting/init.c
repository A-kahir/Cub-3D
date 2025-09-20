/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:11:18 by ifaleh            #+#    #+#             */
/*   Updated: 2025/09/20 16:22:09 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

void	init_player(t_source *src)
{
	src->player->player_px += 0.5;
	src->player->player_py += 0.5;
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

void	init_text(t_source *src)
{
	int	w_n;
	int	h_n;
	int	w_s;
	int	h_s;
	int	w_e;
	int	h_e;
	int	w_w;
	int	h_w;

	src->no_tex.image = mlx_xpm_file_to_image(src->mlx_pointer, src->value, &w_n, &h_n);
	src->sud_tex.image = mlx_xpm_file_to_image(src->mlx_pointer, src->next->value, &w_s, &h_s);
	src->west_tex.image = mlx_xpm_file_to_image(src->mlx_pointer, src->next->next->value, &w_w, &h_w);
	src->est_tex.image = mlx_xpm_file_to_image(src->mlx_pointer, src->next->next->next->value, &w_e, &h_e);
	if (!src->no_tex.image || !src->est_tex.image || !src->sud_tex.image || !src->west_tex.image)
	{
		printf("errorrr\n");
		exit (1);
	}
	src->no_tex.data = mlx_get_data_addr(src->no_tex.image, &src->no_tex.bpp, &src->no_tex.line_len, &src->no_tex.endian);
	src->sud_tex.data = mlx_get_data_addr(src->sud_tex.image, &src->sud_tex.bpp, &src->sud_tex.line_len, &src->sud_tex.endian);
	src->est_tex.data = mlx_get_data_addr(src->est_tex.image, &src->est_tex.bpp, &src->est_tex.line_len, &src->est_tex.endian);
	src->west_tex.data = mlx_get_data_addr(src->west_tex.image, &src->west_tex.bpp, &src->west_tex.line_len, &src->west_tex.endian);
	if (!src->no_tex.data || !src->sud_tex.data || !src->est_tex.data || !src->west_tex.data)
	{
		printf("errorrrrrrrrrr\n");
		exit (1);
	}
	src->no_tex.width = w_n;
	src->no_tex.height = h_n;
	src->sud_tex.width = w_s;
	src->sud_tex.height = h_s;
	src->est_tex.width = w_e;
	src->est_tex.height = h_e;
	src->west_tex.width = w_w;
	src->west_tex.height = h_w;
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}