/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secound_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:00:39 by akahir            #+#    #+#             */
/*   Updated: 2025/09/27 18:43:27 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	ft_secound_parsing(t_source *src)
{
	int			width_img;
	int			height_img;
	t_source	*curr;

	width_img = WIDTH;
	height_img = HEIGHT;
	curr = src;
	while (curr)
	{
		if (curr && curr->var && curr->value
			&& (!ft_strcmp(curr->var, "NO") || !ft_strcmp(curr->var, "SO")
				|| !ft_strcmp(curr->var, "WE") || !ft_strcmp(curr->var, "EA")))
		{
			src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer,
					curr->value, &width_img, &height_img);
			if (!src->mlx_image)
				return (print_message(12, NULL, '\0'), exit(1));
		}
		curr = curr->next;
	}
}
