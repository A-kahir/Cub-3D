/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_but.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 07:25:04 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/08 02:18:12 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

static int	ft_check_door_pos(t_source *src, int i, int l)
{
	if (i == 0 || l == 0 || !src->map[i + 1]
		|| l >= (int)ft_strlen(src->map[i]) - 1)
		return (print_message(13, NULL, '\0'), -1);
	if (src->map[i][l - 1] == 'D' || src->map[i][l + 1] == 'D'
		|| src->map[i - 1][l] == 'D' || src->map[i + 1][l] == 'D')
		return (print_message(13, NULL, '\0'), -1);
	return (0);
}

static int	ft_validate_door(t_source *src, int i, int l, int *index_d)
{
	if ((src->map[i][l - 1] == '1' && src->map[i][l + 1] == '1'
		&& src->map[i - 1][l] != '1' && src->map[i + 1][l] != '1')
		|| (src->map[i - 1][l] == '1' && src->map[i + 1][l] == '1'
		&& src->map[i][l - 1] != '1' && src->map[i][l + 1] != '1'))
	{
		(*index_d)++;
		ft_add_door(src, l, i, *index_d);
		return (0);
	}
	return (print_message(13, NULL, '\0'), -1);
}

static int	ft_check_player_char(t_source *src, int i, int l, int len_j)
{
	if (l > 0 && len_j > i)
	{
		if (src->map[i][l] == '0' || src->map[i][l] == 'N'
			|| src->map[i][l] == 'S' || src->map[i][l] == 'E'
			|| src->map[i][l] == 'W' || src->map[i][l] == 'D')
		{
			if (ft_is_spaces(src->map[i - 1][l]) == 0
				|| ft_is_spaces(src->map[i + 1][l]) == 0)
				return (print_message(4, src->map[i], src->map[i][l]), -1);
		}
	}
	return (0);
}

static int	ft_process_char(t_source *src, int i, int l, int *index_d)
{
	if (src->map[i][l] == 'D')
	{
		if (ft_check_door_pos(src, i, l) == -1)
			return (-1);
		if (ft_validate_door(src, i, l, index_d) == -1)
			return (-1);
	}
	return (0);
}

int	ft_check_up_bottom_valid_chars(t_source *src, int len_j)
{
	int	i;
	int	l;
	int	index_d;

	i = 1;
	index_d = 0;
	while (src && src->map && src->map[i])
	{
		l = 0;
		while (src->map[i][l] != '\0')
		{
			if (ft_process_char(src, i, l, &index_d) == -1)
				return (-1);
			if (ft_check_player_char(src, i, l, len_j) == -1)
				return (-1);
			l++;
		}
		i++;
	}
	return (0);
}
