/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:17:42 by akahir            #+#    #+#             */
/*   Updated: 2025/10/06 21:45:00 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

char	ft_check(t_source *src, int r, int c)
{
	if (r < 0 || r >= HEIGHT)
		return (' ');
	if (!src->map[r])
		return (' ');
	if (c < 0 || c >= (int)ft_strlen(src->map[r]))
		return (' ');
	if (src->map[r][c] == '0' || src->map[r][c] == '1'
		|| src->map[r][c] == 'N' || src->map[r][c] == 'S'
		|| src->map[r][c] == 'E' || src->map[r][c] == 'W' || src->map[r][c] == 'D')
		return (src->map[r][c]);
	return (' ');
}

int	check_corner_and_side(t_source *src, int i, int l)
{
	char	curr;

	curr = ft_check(src, i, l);
	if (curr == '0' || curr == 'N' || curr == 'S' || curr == 'E' || curr == 'W' || curr == 'D')
	{
		if (ft_check(src, i - 1, l - 1) == ' ')
			return (-1);
		if (ft_check(src, i + 1, l + 1) == ' ')
			return (-1);
		if (ft_check(src, i + 1, l - 1) == ' ')
			return (-1);
		if (ft_check(src, i - 1, l + 1) == ' ')
			return (-1);
		if (ft_check(src, i - 1, l) == ' ')
			return (-1);
		if (ft_check(src, i + 1, l) == ' ')
			return (-1);
		if (ft_check(src, i, l - 1) == ' ')
			return (-1);
		if (ft_check(src, i, l + 1) == ' ')
			return (-1);
	}
	return (0);
}

int	ft_check_corners(t_source *src, int i, int l)
{
	if (check_corner_and_side(src, i, l) == -1)
		return (ft_debug_map(src->map[i], l),
			print_message(4, src->map[i], src->map[i][l]), -1);
	return (0);
}

int	ft_check_middle_chars(t_source *src, int i, int len_j)
{
	int	l;

	if (i <= 0 || len_j <= i)
		return (0);
	l = 0;
	while (src->map[i][l] != '\0')
	{
		if (src->map[i][l] == '0' || (src->map[i][l] == 'N'
			|| src->map[i][l] == 'S' || src->map[i][l] == 'E'
			|| src->map[i][l] == 'W' || src->map[i][l] == 'D'))
		{
			if (ft_check_corners(src, i, l) == -1)
				return (-1);
		}
		l++;
	}
	return (0);
}

int	ft_check_spaces_zone(t_source *src, int i, int l, int len_i)
{
	if (ft_is_spaces(src->map[i][l + 1]) == 0)
	{
		if (src->map[i][l] != '1' && !(ft_is_spaces(src->map[i][l]) == 0))
			return (ft_debug_map(src->map[i], l),
				print_message(4, src->map[i], src->map[i][l]), -1);
	}
	else if (l > 0 && ft_is_spaces(src->map[i][l - 1]) == 0)
	{
		if (src->map[i][l] != '1' && !(ft_is_spaces(src->map[i][l]) == 0))
			return (ft_debug_map(src->map[i], l),
				print_message(4, src->map[i], src->map[i][l]), -1);
	}
	else if (l == len_i)
	{
		if (src->map[i][l] != '1')
			if (ft_is_spaces(src->map[i][l]) == -1)
				return (ft_debug_map(src->map[i], l),
					print_message(4, src->map[i], src->map[i][l]), -1);
	}
	return (0);
}
