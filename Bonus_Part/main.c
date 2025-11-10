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

#include "cub_bonus.h"

static void	*ft_open_mlx_window(t_source *src)
{
	src->mlx_pointer = mlx_init();
	if (!src->mlx_pointer)
		return (print_message(3, NULL, '\0'), NULL);
	src->mlx_window = mlx_new_window(src->mlx_pointer,
			WIDTH, HEIGHT, "- Paradise & Hell -");
	if (!src->mlx_window)
		return (print_message(3, NULL, '\0'), NULL);
	src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer,
			"Bonus_Part/Parssing_b/texture/first_page.xpm",
			&src->width, &src->height);
	if (!src->mlx_image)
		return (write(2, "mlx image failed11\n", 19), NULL);
	mlx_put_image_to_window(src->mlx_pointer,
		src->mlx_window, src->mlx_image, 0, 0);
	mlx_hook(src->mlx_window, 2, (1L << 0), ft_key_theme_b, src);
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
		return (print_message(1, NULL, '\0'), malloc_cl(0, 2), 1);
	src->mlx_pointer = ft_open_mlx_window(src);
	if (!src->mlx_pointer)
		return (ft_free_mlx(src), malloc_cl(0, 2), 1);
	mlx_hook(src->mlx_window, 17, 0, handle_close, src);
	mlx_loop(src->mlx_pointer);
}
