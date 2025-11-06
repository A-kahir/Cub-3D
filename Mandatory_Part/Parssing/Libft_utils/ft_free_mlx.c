/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:53:37 by akahir            #+#    #+#             */
/*   Updated: 2025/11/06 23:29:46 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

void	ft_free_mlx(t_source *src)
{
	if (src->render_image)
		mlx_destroy_image(src->mlx_pointer, src->render_image);
	if (src->no_tex.image)
		mlx_destroy_image(src->mlx_pointer, src->no_tex.image);
	if (src->sud_tex.image)
		mlx_destroy_image(src->mlx_pointer, src->sud_tex.image);
	if (src->est_tex.image)
		mlx_destroy_image(src->mlx_pointer, src->est_tex.image);
	if (src->west_tex.image)
		mlx_destroy_image(src->mlx_pointer, src->west_tex.image);
	if (src->mlx_window)
		mlx_destroy_window(src->mlx_pointer, src->mlx_window);
	if (src->mlx_image)
		mlx_destroy_image(src->mlx_pointer, src->mlx_image);
	if (src->mlx_pointer)
	{
		free(src->mlx_pointer);
		src->mlx_pointer = NULL;
		src->mlx_window = NULL;
		src->mlx_image = NULL;
		src->render_image = NULL;
	}
}
