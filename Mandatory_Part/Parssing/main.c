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

#include "parsing.h"

static void	*ft_open_mlx_window(t_source *src)
{
	void *mlx_pointer;
	void *mlx_window;
	void *image_pointer;
	int hight;
	int width;

	mlx_pointer = mlx_init();
	if (!mlx_pointer)
		return (print_message(3, NULL, '\0'), NULL);
	hight = 550;
	width = 850;
	mlx_window = mlx_new_window(mlx_pointer, width, hight, "Paradise");
	if (!mlx_window)
		return (print_message(3, NULL, '\0'), NULL);
	image_pointer = mlx_new_image(mlx_pointer, width, hight);
	if (!image_pointer)
		return (print_message(3, NULL, '\0'), NULL);
	int bits_px;
	int size_bits;
	int endian;
	char *add = mlx_get_data_addr(image_pointer, &bits_px, &size_bits, &endian);
	if (!add)
		return (print_message(3, NULL, '\0'), NULL);
	int y = 0;
	char *pixel;
	t_source *curr = src;
	while (y < hight)
	{
		int x = 0;
		while (x < width)
		{
			pixel = add + (y * size_bits + x * (bits_px / 8));
			if (y < hight / 2)
			{
				while (curr)
				{
					if (curr->colors)
					{
						if (curr->colors->hexa_rgb_f)
							break ;
					}
					curr = curr->next;
				}
				*(unsigned int *)pixel = curr->colors->hexa_rgb_f;
			}
			else if (y >= hight / 2)
			{
				while (curr)
				{
					if (curr->colors)
					{
						if (curr->colors->hexa_rgb_c)
						{
							break ;
						}
					}
					curr = curr->next;
				}
				*(unsigned int *)pixel = curr->colors->hexa_rgb_c;
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_pointer, mlx_window, image_pointer, 0, 0);
	return (mlx_pointer);
}

int	main(int argc, char **argv)
{
	t_source	*src;
	void *mlx_ptr;

	src = NULL;
	if (ft_parsing(argc, argv) == -1)
		return (1);
	src = ft_get_source(src, argv[1]);
	if (!src)
		return (print_message(1, NULL, '\0'), 1);
	t_source *curr = src;
	ft_debug(curr, 1);
	mlx_ptr = ft_open_mlx_window(src);
	if (!mlx_ptr)
		return (-1);
	mlx_loop(mlx_ptr);
}
