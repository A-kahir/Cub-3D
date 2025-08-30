/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_before_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 04:11:10 by akahir            #+#    #+#             */
/*   Updated: 2025/08/30 21:50:20 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

int ft_prepare_hexa_rgb(t_source *src, t_source *curr)
{
	char **colors_rgb;

	if (!curr->value)
		return (-1);
	colors_rgb = ft_split(curr->value, ',');
	if (!colors_rgb)
		return (perror("split failed"), -1);
	if (colors_rgb[0] == NULL || colors_rgb[1] == NULL || colors_rgb[2] == NULL || colors_rgb[3])
		return (perror("you have more or less value"), -1);
	src->colors = malloc_cl(sizeof(t_colors), 0);
	if (!src->colors)
		return (-1);
	if (colors_rgb[0])
		src->colors->r = ft_atoi(colors_rgb[0]);
	if (colors_rgb[1])
		src->colors->g = ft_atoi(colors_rgb[1]);
	if (colors_rgb[2])
		src->colors->b = ft_atoi(colors_rgb[2]);
	if (src->colors->r  == -1|| src->colors->g == -1 || src->colors->b == -1)
		return (perror("atoi overflow or failed"), -1);
	return (0);
}

int ft_check_before_map(t_source *src)
{
	t_source *curr;

	curr = src;
	while (curr)
	{
		if (!curr->value)
			return (-1);
		if (ft_strcmp(curr->var, "F") == 0 || ft_strcmp(curr->var, "C") == 0)
			if (ft_prepare_hexa_rgb(src, curr) == -1)
				return (-1);
		curr = curr->next;
	}
	if (src && src->var && ft_strcmp(src->var, "NO") == 0)
		if (src->next && ft_strcmp(src->next->var, "SO") == 0)
			if (src->next->next && ft_strcmp(src->next->next->var, "WE") == 0)
				if (src->next->next->next && ft_strcmp(src->next->next->next->var, "EA") == 0)
					if (src->next->next->next->next && ft_strcmp(src->next->next->next->next->var, "F") == 0)
						if (src->next->next->next->next->next && ft_strcmp(src->next->next->next->next->next->var, "C") == 0)
							return (0);
	return (-1);
}
