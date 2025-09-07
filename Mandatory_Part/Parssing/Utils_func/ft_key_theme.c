/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:46:59 by akahir            #+#    #+#             */
/*   Updated: 2025/09/07 23:27:27 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"
int	ft_key_theme(int key, t_source *src)
{
	int w = src->width;
	int h = src->hight;
	t_source *curr;

	printf("key ==> %d\n", key);

	if (key == 19 || key == 18)
	{
		if (src->mlx_image)
		{
			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
			src->mlx_image = NULL;
		}
		if (key == 19)
		{
			printf("is selected HELL\n");
			curr = src;
			while (curr)
			{
				if (ft_strcmp(curr->var, "NO") == 0 && curr->value)
					printf("=====> NO\n");
				else if (ft_strcmp(curr->var, "SO") == 0 && curr->value)
					printf("=====> SO\n");
				else if (ft_strcmp(curr->var, "WE") == 0 && curr->value)
					printf("=====> WE\n");
				else if (ft_strcmp(curr->var, "EA") == 0 && curr->value)
					printf("=====> EA\n");
				else if (ft_strcmp(curr->var, "F") == 0 && curr->colors)
				{
					printf("=====> F\n");
					curr->colors->hexa_rgb_f = 970606;
				}
				else if (ft_strcmp(curr->var, "C") == 0 && curr->colors)
				{
					printf("=====> C\n");
					curr->colors->hexa_rgb_c = 161616;
				}
				curr = curr->next;
			}
		}
		src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer, "Parssing/texture/Loading.xpm", &w, &h);
		if (src->mlx_image)
			mlx_put_image_to_window(src->mlx_pointer, src->mlx_window, src->mlx_image, 0, 0);
		else
			write(2, "mlx image failed\n", 18);
		return (1);
	}
	return (-1);
}
