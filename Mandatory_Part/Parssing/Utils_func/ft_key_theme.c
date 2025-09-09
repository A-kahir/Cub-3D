/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:46:59 by akahir            #+#    #+#             */
/*   Updated: 2025/09/09 17:16:28 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	ft_key_loading(int key, t_source *src)
{
	if (key == 36)
	{
		ft_secound_parsing(src);
		if (src->mlx_image)
		{
			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
			src->mlx_image = NULL;
		}
		printf("==> now you will start game\n**************************\n");
		ft_debug(src, 2);
	}
	return (-1);
}

int	ft_key_theme(int key, t_source *src)
{
	int	w;
	int	h;

	w = src->width;
	h = src->hight;
	if (key == 19 || key == 18)
	{
		if (src->mlx_image)
		{
			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
			src->mlx_image = NULL;
		}
		if (key == 19)
			ft_is_hell(src);
		src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer,
				"Parssing/texture/Loading_page.xpm", &w, &h);
		if (src->mlx_image)
			mlx_put_image_to_window(src->mlx_pointer,
				src->mlx_window, src->mlx_image, 0, 0);
		else
			return (write(2, "mlx image failed\n", 18), -1);
		return (mlx_key_hook(src->mlx_window, ft_key_loading, src), 1);
	}
	return (-1);
}
