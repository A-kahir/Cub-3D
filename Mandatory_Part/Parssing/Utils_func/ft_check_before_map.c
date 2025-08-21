/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_before_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 04:11:10 by akahir            #+#    #+#             */
/*   Updated: 2025/08/21 17:24:48 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

int ft_check_before_map(t_source *src)
{
	t_source *curr;
	char **colors_rgb;

	curr = src;
	while (curr)
	{
		if (ft_strcmp(curr->var, "F") == 0 || ft_strcmp(curr->var, "C") == 0)
		{
			colors_rgb = ft_split(curr->value, ',');
			printf("colors R ==> %s\n", colors_rgb[0]);
			printf("colors g ==> %s\n", colors_rgb[1]);
			printf("colors b ==> %s\n", colors_rgb[2]);
		}
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
