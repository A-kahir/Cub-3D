/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 03:58:42 by ifaleh            #+#    #+#             */
/*   Updated: 2025/09/27 18:30:23 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

int	get_map_height(char **map)
{
	int	h;

	h = 0;
	while (map[h])
		h++;
	return (h);
}

int	get_map_width(char **map)
{
	int	max_w;
	int	i;
	int	len;

	max_w = 0;
	i = 0;
	while (map[i])
	{
		len = strlen(map[i]);
		if (len > max_w)
			max_w = len;
		i++;
	}
	return (max_w);
}

void	my_put_pixel(char *data, t_source *src, int x, int y, int color)
{
	int	pos;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pos = (y * src->line_len + x * (src->bpp / 8));
	*(unsigned int *)(data + pos) = color;
}