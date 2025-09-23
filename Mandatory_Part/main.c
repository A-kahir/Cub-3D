/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:08:25 by akahir            #+#    #+#             */
/*   Updated: 2025/08/15 16:08:25 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_mand.h"

static void	*ft_open_mlx_window(t_source *src)
{
	int	width_img;
	int	height_img;

	src->mlx_pointer = mlx_init();
	if (!src->mlx_pointer)
		return (print_message(3, NULL, '\0'), NULL);
	src->mlx_window = mlx_new_window(src->mlx_pointer,
			src->width, src->height, "- HELL -");
	if (!src->mlx_window)
		return (print_message(3, NULL, '\0'), NULL);
	width_img = src->width;
	height_img = src->height;
	// src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer,
	// 		"Parssing/texture/first_page.xpm", &width_img, &height_img);
	// if (!src->mlx_image)
	// 	return (write(2, "mlx image failed\n", 18), NULL);
	// mlx_put_image_to_window(src->mlx_pointer,
	// 	src->mlx_window, src->mlx_image, 0, 0);
	ft_key_theme(src);
	return (src->mlx_pointer);
}

int	main(int argc, char **argv)
{
	t_source	*src;

	src = NULL;
	if (ft_parsing(argc, argv) == -1)
		return (1);
	src = ft_get_source(src, argv[1]);
	if (!src)
		return (print_message(1, NULL, '\0'), 1);
	src->mlx_pointer = ft_open_mlx_window(src);
	if (!src->mlx_pointer)
		return (-1);
	mlx_loop(src->mlx_pointer);
	malloc_cl(0, 1);
}
