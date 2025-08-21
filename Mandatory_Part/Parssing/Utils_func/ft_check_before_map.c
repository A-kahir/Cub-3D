/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_before_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 04:11:10 by akahir            #+#    #+#             */
/*   Updated: 2025/08/21 14:28:15 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

int ft_check_before_map(t_source *src)
{
	t_source *curr;

	curr = src;
	while (curr)
	{
		if (!curr->value)
			return (-1);
		curr = curr->next;
	}
	if (ft_strcmp(src->var, "NO") == 0)
		if (ft_strcmp(src->next->var, "SO") == 0)
			if (ft_strcmp(src->next->next->var, "WE") == 0)
				if (ft_strcmp(src->next->next->next->var, "EA") == 0)
					if (ft_strcmp(src->next->next->next->next->var, "F") == 0)
						if (ft_strcmp(src->next->next->next->next->next->var, "C") == 0)
							return (0);
	return (-1);
}
