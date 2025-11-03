/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_but.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:54:13 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/03 16:32:31 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

static int	ft_check_player_char(t_source *src, int i, int l, int len_j)
{
	if (l > 0 && len_j > i)
	{
		if (src->map[i][l] == '0' || src->map[i][l] == 'N'
			|| src->map[i][l] == 'S' || src->map[i][l] == 'E'
			|| src->map[i][l] == 'W')
		{
			if (ft_is_spaces(src->map[i - 1][l]) == 0
				|| ft_is_spaces(src->map[i + 1][l]) == 0)
				return (ft_debug_map(src->map[i], l),
					print_message(4, src->map[i], src->map[i][l]), -1);
		}
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
			if (ft_check_player_char(src, i, l, len_j) == -1)
				return (-1);
			l++;
		}
		i++;
	}
	return (0);
}