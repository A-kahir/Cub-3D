/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secound_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:00:39 by akahir            #+#    #+#             */
/*   Updated: 2025/09/08 18:33:38 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void ft_secound_parsing(t_source *src)
{
	int width_img;
	int hight_img;
	t_source *curr;

	width_img = src->width;
	hight_img = src->hight;
	curr = src;
	while (curr)
	{
		if (curr && curr->var && curr->value
			&& (ft_strcmp(curr->var, "NO") == 0 || ft_strcmp(curr->var, "SO") == 0
			|| ft_strcmp(curr->var, "WE") == 0 || ft_strcmp(curr->var, "EA") == 0))
		{
			src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer, curr->value, &width_img, &hight_img);
			if (!src->mlx_image)
				return (print_message(12, NULL, '\0'), exit(1));
		}
		curr = curr->next;
	}
}
