/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:28:06 by akahir            #+#    #+#             */
/*   Updated: 2025/11/11 18:23:43 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

static int	ft_check_first_last_row(t_source *src, int i, int len_j)
{
	int	l;

	l = 0;
	while (src->map[i][l])
	{
		if (src->map[i][l] != '1')
		{
			if (ft_is_spaces(src->map[i][l]) == -1 && i == 0)
				return (print_message(2, src->map[i], src->map[i][l]), -1);
			if (ft_is_spaces(src->map[i][l]) == -1 && i == len_j)
				return (print_message(7, src->map[i], src->map[i][l]), -1);
		}
		l++;
	}
	return (0);
}

static int	ft_check_cadring_map(t_source *src, int i, int len_i)
{
	int	l;

	l = 0;
	while (src->map[i][l] != '\0')
	{
		if (src->map[i][l])
		{
			if (l == 0 && src->map[i][l] != '1'
				&& ((src->map[i][l + 1] || src->map[i][l - 1])
				!= (ft_is_spaces(src->map[i][l]) == 0)))
			{
				if (!(ft_is_spaces(src->map[i][l]) == 0
					|| (src->map[i][l] == 'N') || (src->map[i][l] == 'S')
					|| (src->map[i][l] == 'W') || (src->map[i][l] == 'E')))
					return (print_message(4, src->map[i], src->map[i][l]), -1);
			}
			else if (ft_check_spaces_zone(src, i, l, len_i) == -1)
				return (-1);
		}
		l++;
	}
	return (0);
}

static int	ft_check_vertical_spaces(t_source *src, int i, int len_j)
{
	int	l;
	int	sv_po;

	if (i <= 0 || len_j <= i || !((ft_is_spaces(src->map[i + 1][0]) == 0)
		|| (ft_is_spaces(src->map[i - 1][0]) == 0)))
		return (0);
	l = 0;
	while (src->map[i][l] != '\0')
	{
		if (src->map[i][l] != '1' && ft_is_spaces(src->map[i][l]) == -1)
		{
			if (l > 0 && src->map[i][l - 1] == '1' && src->map[i][l + 1] == '1')
			{
				sv_po = l;
				if (ft_is_spaces(src->map[i + 1][sv_po]) == 0)
					return (print_message(4, src->map[i],
							src->map[i][sv_po]), -1);
				else if (ft_is_spaces(src->map[i - 1][sv_po]) == 0)
					return (print_message(4, src->map[i],
							src->map[i][sv_po]), -1);
			}
		}
		1 && (l++, sv_po = 0);
	}
	return (0);
}

int	ft_parse_map(t_source *src)
{
	int	i;
	int	len_j;
	int	len_i;

	ft_add_spaces_in_map(src);
	1 && (len_j = ft_lenght_j(src), i = 0);
	while (src && src->map && src->map[i])
	{
		len_i = ft_strlen(src->map[i]) - 1;
		if (i == 0 || i == len_j)
		{
			if (ft_check_first_last_row(src, i, len_j) == -1)
				return (-1);
		}
		if (ft_check_middle_chars(src, i, len_j) == -1)
			return (-1);
		if (i > 0 && ft_check_cadring_map(src, i, len_i) == -1)
			return (-1);
		if (ft_check_vertical_spaces(src, i, len_j) == -1)
			return (-1);
		if (ft_valid_char_rows(src, i, len_j) == -1)
			return (-1);
		i++;
	}
	return (ft_check_up_bottom_valid_chars(src, len_j));
}
