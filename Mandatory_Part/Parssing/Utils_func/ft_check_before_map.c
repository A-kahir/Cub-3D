/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_before_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 04:11:10 by akahir            #+#    #+#             */
/*   Updated: 2025/10/31 17:37:28 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

static int	ft_fill_struct_colors(t_source *src, char **colors_rgb)
{
	int	r;
	int	g;
	int	b;

	if (!src)
		return (-1);
	r = ft_atoi(colors_rgb[0]);
	g = ft_atoi(colors_rgb[1]);
	b = ft_atoi(colors_rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (print_message(11, NULL, '\0'), -1);
	if (ft_strcmp(src->var, "F") == 0)
		src->colors->hexa_rgb_f = ((r << 16) | (g << 8) | b);
	else if (ft_strcmp(src->var, "C") == 0)
		src->colors->hexa_rgb_c = ((r << 16) | (g << 8) | b);
	return (0);
}

static int	ft_prepare_hexa_rgb(t_source *curr)
{
	char	**colors_rgb;
	int		i;
	int		j;
	char	*check;

	1 && (check = curr->value, i = 0);
	while (check[i++])
		if ((check[i] == ',' && check[i + 1] == ',') || check[0] == ',')
			return (print_message(11, NULL, '\0'), exit(1), -1);
	colors_rgb = ft_split(curr->value, ',');
	if (!colors_rgb || !colors_rgb[0] || !colors_rgb[1]
		|| !colors_rgb[2] || colors_rgb[3] != NULL
		|| curr->value[ft_strlen(curr->value) - 1] == ',')
		return (print_message(11, NULL, '\0'), exit(1), -1);
	i = -1;
	while (colors_rgb[++i])
	{
		j = -1;
		while (colors_rgb[i][++j] != '\0')
			if (!(colors_rgb[i][j] >= '0' && colors_rgb[i][j] <= '9'))
				return (print_message(10, NULL, '\0'), -1);
	}
	if (ft_fill_struct_colors(curr, colors_rgb) == -1)
		return (-1);
	return (0);
}

static int	ft_hexa_colors(t_source *src, int *hexa_f, int *hexa_c)
{
	t_source	*curr;
	char		*check;

	1 && (*hexa_f = -1, *hexa_c = -1, curr = src, check = NULL);
	while (curr)
	{
		if (!curr->value)
			return (-1);
		if (ft_strcmp(curr->var, "F") == 0 || ft_strcmp(curr->var, "C") == 0)
		{
			if (!curr->value || (check && ft_strcmp(curr->var, check) == 0))
				return (-1);
			if (ft_prepare_hexa_rgb(curr) == -1)
				return (-1);
			check = curr->var;
		}
		if (ft_strcmp(curr->var, "F") == 0)
			*hexa_f = curr->colors->hexa_rgb_f;
		if (ft_strcmp(curr->var, "C") == 0)
			*hexa_c = curr->colors->hexa_rgb_c;
		curr = curr->next;
	}
	if (*hexa_f == -1 || *hexa_c == -1)
		return (-1);
	return (0);
}

int	ft_check_before_map(t_source *src)
{
	t_source	*curr;
	int			hexa_f;
	int			hexa_c;

	if (ft_hexa_colors(src, &hexa_f, &hexa_c) == -1)
		return (-1);
	curr = src;
	while (curr)
	{
		if (curr->colors)
		{
			curr->colors->hexa_rgb_f = hexa_f;
			curr->colors->hexa_rgb_c = hexa_c;
		}
		curr = curr->next;
	}
	if (ft_stop_reading(src) == 0)
		return (0);
	return (-1);
}
