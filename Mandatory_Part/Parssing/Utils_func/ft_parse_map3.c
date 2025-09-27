/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:25:02 by akahir            #+#    #+#             */
/*   Updated: 2025/09/27 18:29:02 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

int	ft_valid_char_rows(t_source *src, int i, int len_j)
{
	int	l;

	if (i == 0 || i == len_j)
		return (0);
	l = 1;
	while (src->map[i][l + 1] != '\0')
	{
		if (src->map[i][l] != '0' && src->map[i][l] != '1'
			&& ft_is_spaces(src->map[i][l]) == -1
			&& !(src->map[i][l] == 'N' || src->map[i][l] == 'S'
			|| src->map[i][l] == 'E' || src->map[i][l] == 'W'))
			return (ft_debug_map(src->map[i], l),
				print_message(4, src->map[i], src->map[i][l]), -1);
		l++;
	}
	return (0);
}
