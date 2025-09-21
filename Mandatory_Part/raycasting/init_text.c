/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 03:15:18 by ifaleh            #+#    #+#             */
/*   Updated: 2025/09/21 04:12:15 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

static void	init_text_img(t_source *src)
{
	src->no_tex.image = mlx_xpm_file_to_image(src->mlx_pointer, src->value,
			&src->no_tex.width, &src->no_tex.height);
	src->sud_tex.image = mlx_xpm_file_to_image(src->mlx_pointer,
			src->next->value, &src->sud_tex.width, &src->sud_tex.height);
	src->west_tex.image = mlx_xpm_file_to_image(src->mlx_pointer,
			src->next->next->value, &src->west_tex.width,
			&src->west_tex.height);
	src->est_tex.image = mlx_xpm_file_to_image(src->mlx_pointer,
			src->next->next->next->value, &src->est_tex.width,
			&src->est_tex.height);
	if (!src->no_tex.image || !src->sud_tex.image
		|| !src->west_tex.image || !src->est_tex.image)
	{
		perror("Error\nFailed to load texture images\n");
		exit(1);
	}
}

void	init_text(t_source *src)
{
	init_text_img(src);
	src->no_tex.data = mlx_get_data_addr(src->no_tex.image, &src->no_tex.bpp,
			&src->no_tex.line_len, &src->no_tex.endian);
	src->sud_tex.data = mlx_get_data_addr(src->sud_tex.image, &src->sud_tex.bpp,
			&src->sud_tex.line_len, &src->sud_tex.endian);
	src->west_tex.data = mlx_get_data_addr(src->west_tex.image,
			&src->west_tex.bpp, &src->west_tex.line_len, &src->west_tex.endian);
	src->est_tex.data = mlx_get_data_addr(src->est_tex.image, &src->est_tex.bpp,
			&src->est_tex.line_len, &src->est_tex.endian);
	if (!src->no_tex.data || !src->sud_tex.data
		|| !src->west_tex.data || !src->est_tex.data)
	{
		perror("Error\nFailed to get texture data\n");
		exit(1);
	}
}
