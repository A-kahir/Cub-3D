/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 03:15:18 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/06 21:23:56 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

static void	init_text_img(t_source *src)
{
	src->no_tex.image = mlx_xpm_file_to_image(src->mlx_pointer,
			src->no_tex.path,
			&src->no_tex.width, &src->no_tex.height);
	src->sud_tex.image = mlx_xpm_file_to_image(src->mlx_pointer,
			src->sud_tex.path, &src->sud_tex.width, &src->sud_tex.height);
	src->west_tex.image = mlx_xpm_file_to_image(src->mlx_pointer,
			src->west_tex.path, &src->west_tex.width,
			&src->west_tex.height);
	src->est_tex.image = mlx_xpm_file_to_image(src->mlx_pointer,
			src->est_tex.path, &src->est_tex.width,
			&src->est_tex.height);
	src->doors_tex.image = mlx_xpm_file_to_image(src->mlx_pointer,
			src->doors_tex.path,
			&src->doors_tex.width, &src->doors_tex.height);
	if (!src->no_tex.image || !src->sud_tex.image
		|| !src->west_tex.image || !src->est_tex.image || !src->doors_tex.image)
	{
		perror("Error\nFailed to load texture images");
		ft_free_mlx(src);
		malloc_cl(0, 1);
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
	src->doors_tex.data = mlx_get_data_addr(src->doors_tex.image,
			&src->doors_tex.bpp,
			&src->doors_tex.line_len, &src->doors_tex.endian);
	if (!src->no_tex.data || !src->sud_tex.data
		|| !src->west_tex.data || !src->est_tex.data || !src->doors_tex.data)
	{
		perror("Error\nFailed to get texture data\n");
		exit(1);
	}
}

t_tex	*select_texture(t_source *src, t_raycast *ray)
{
	if (ray->wall_dir == 0)
		return (&src->no_tex);
	else if (ray->wall_dir == 1)
		return (&src->sud_tex);
	else if (ray->wall_dir == 2)
		return (&src->west_tex);
	else if (ray->wall_dir == 3)
		return (&src->est_tex);
	else
		return (&src->doors_tex);
}

int	calculate_tex_x(t_source *src, t_raycast *ray, t_tex *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = src->p->p_py + ray->perpwalldis * ray->ray_dir_y;
	else
		wall_x = src->p->p_px + ray->perpwalldis * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	if (tex_x < 0 || tex_x >= tex->width)
	{
		printf("Error: tex_x=%d out of bounds (width=%d)\n",
			tex_x, tex->width);
		if (tex_x < 0)
			tex_x = 0;
		else
			tex_x = tex->width - 1;
	}
	return (tex_x);
}
