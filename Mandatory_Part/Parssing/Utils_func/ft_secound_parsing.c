/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secound_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:00:39 by akahir            #+#    #+#             */
/*   Updated: 2025/11/06 16:58:50 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

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
}

void	ft_sec_parsing(t_source *src)
{
	int			width_img;
	int			height_img;
	t_source	*curr;

	width_img = WIDTH;
	height_img = HEIGHT;
	curr = src;
	while (curr && curr->mlx_pointer && src->mlx_pointer)
	{
		curr->mlx_pointer = src->mlx_pointer;
		curr = curr->next;
	}
	while (curr)
	{
		if (curr && curr->var && curr->value
			&& (!ft_strcmp(curr->var, "NO") || !ft_strcmp(curr->var, "SO")
				|| !ft_strcmp(curr->var, "WE") || !ft_strcmp(curr->var, "EA")))
		{
			curr->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer,
					curr->value, &width_img, &height_img);
			if (!src->mlx_image)
				return (print_message(12, NULL, '\0'), exit(1));
			fill_textures(src, curr->var, curr->value);
		}
		curr = curr->next;
	}
}
