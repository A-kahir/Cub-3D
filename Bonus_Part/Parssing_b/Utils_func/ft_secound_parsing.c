/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secound_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:00:39 by akahir            #+#    #+#             */
/*   Updated: 2025/11/07 04:49:54 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	fill_textures(t_source *src, char *var, char *value)
{
	if (!ft_strcmp(var, "NO"))
		src->no_tex.path = value;
	if (!ft_strcmp(var, "SO"))
		src->sud_tex.path = value;
	if (!ft_strcmp(var, "EA"))
		src->est_tex.path = value;
	if (!ft_strcmp(var, "WE"))
		src->west_tex.path = value;
	if (!ft_strcmp(var, "DR"))
		src->doors_tex.path = value;
}

void	ft_fill_mlx_ptr(t_source *src)
{
	t_source	*tmp;

	tmp = src;
	while (tmp && tmp->mlx_pointer && src->mlx_pointer)
	{
		tmp->mlx_pointer = src->mlx_pointer;
		tmp = tmp->next;
	}
}

void	ft_sec_parsing(t_source *src)
{
	int			width_img;
	int			height_img;
	t_source	*curr;

	1 & (width_img = WIDTH, height_img = HEIGHT);
	ft_fill_mlx_ptr(src);
	curr = src;
	while (curr)
	{
		if (curr && curr->var && curr->value
			&& (!ft_strcmp(curr->var, "NO") || !ft_strcmp(curr->var, "SO")
				|| !ft_strcmp(curr->var, "WE") || !ft_strcmp(curr->var, "EA")
				|| !ft_strcmp(curr->var, "DR")))
		{
			curr->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer,
					curr->value, &width_img, &height_img);
			if (!src->mlx_image)
				return (print_message(12, NULL, '\0'),
					ft_free_mlx(src), malloc_cl(0, 1), (void) NULL);
			if (curr->mlx_image && src->mlx_pointer)
				mlx_destroy_image(src->mlx_pointer, curr->mlx_image);
			fill_textures(src, curr->var, curr->value);
		}
		curr = curr->next;
	}
}
