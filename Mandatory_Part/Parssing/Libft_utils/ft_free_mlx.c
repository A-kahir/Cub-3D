/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:53:37 by akahir            #+#    #+#             */
/*   Updated: 2025/11/07 20:50:06 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

void	ft_free_mlx(t_source *src)
{
	t_source *curr;

	if (!src)
		return;
	curr = src;
	while (curr)
	{
		if (curr->mlx_image && curr->mlx_pointer)
			mlx_destroy_image(curr->mlx_pointer, curr->mlx_image);
		curr = curr->next;
	}
	if (src->render_image && src->mlx_pointer)
		mlx_destroy_image(src->mlx_pointer, src->render_image);
	if (src->no_tex.image && src->mlx_pointer)
		mlx_destroy_image(src->mlx_pointer, src->no_tex.image);
	if (src->sud_tex.image && src->mlx_pointer)
		mlx_destroy_image(src->mlx_pointer, src->sud_tex.image);
	if (src->est_tex.image && src->mlx_pointer)
		mlx_destroy_image(src->mlx_pointer, src->est_tex.image);
	if (src->west_tex.image && src->mlx_pointer)
		mlx_destroy_image(src->mlx_pointer, src->west_tex.image);
	if (src->mlx_window && src->mlx_pointer)
		mlx_destroy_window(src->mlx_pointer, src->mlx_window);
	if (src->mlx_pointer)
	{
		mlx_destroy_display(src->mlx_pointer);
		free(src->mlx_pointer);
		src->mlx_pointer = NULL;
	}
}
