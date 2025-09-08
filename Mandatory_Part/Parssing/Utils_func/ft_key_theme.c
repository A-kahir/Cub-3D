/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:46:59 by akahir            #+#    #+#             */
/*   Updated: 2025/09/08 18:32:55 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int ft_key_loading(int key, t_source *src)
{
	if (key == 36)
	{
		ft_secound_parsing(src);
		if (src->mlx_image)
		{
			printf("*****************************\n");
			mlx_destroy_image(src->mlx_pointer, src->mlx_image);
			src->mlx_image = NULL;
		}
		printf("==> now you will start game\n**************************\n");// game starting from her a M.ifaleh
		t_source *curr = src;
		ft_debug(curr, 1);
	}
	return (-1);
}


void ft_is_hell(t_source *src)
{
	t_source *curr;

	printf("HELL is selected\n");
	curr = src;
	while (curr)
	{
		if (ft_strcmp(curr->var, "NO") == 0 && curr->value)
			curr->value = "Parssing/texture/HELL/NO_hell.xpm";
		else if (ft_strcmp(curr->var, "SO") == 0 && curr->value)
			curr->value = "Parssing/texture/HELL/SO_hell.xpm";
		else if (ft_strcmp(curr->var, "WE") == 0 && curr->value)
			curr->value = "Parssing/texture/HELL/WE_hell.xpm";
		else if (ft_strcmp(curr->var, "EA") == 0 && curr->value)
			curr->value = "Parssing/texture/HELL/EA_hell.xpm";
		else if (ft_strcmp(curr->var, "F") == 0 && curr->colors)
			curr->colors->hexa_rgb_f = 610000;
		else if (ft_strcmp(curr->var, "C") == 0 && curr->colors)
			curr->colors->hexa_rgb_c = 161616;
		curr = curr->next;
	}
}

int	ft_key_theme(int key, t_source *src)
{
	int w;
	int h;

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
		src->mlx_image = mlx_xpm_file_to_image(src->mlx_pointer, "Parssing/texture/Loading_page.xpm", &w, &h);
		if (src->mlx_image)
			mlx_put_image_to_window(src->mlx_pointer, src->mlx_window, src->mlx_image, 0, 0);
		else
			return (write(2, "mlx image failed\n", 18), -1);
		return (mlx_hook(src->mlx_window, 2, 1L << 0, ft_key_loading, src), 1);
	}
	return (-1);
}
