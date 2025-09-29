/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_door_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 23:05:49 by akahir            #+#    #+#             */
/*   Updated: 2025/09/28 23:06:13 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	ft_add_door(t_source *src, int x, int y)
{
	t_doors	*new_door;
	t_doors	*tmp;

	new_door = malloc_cl(sizeof(t_doors), 0);
	if (!new_door)
		return ;
	new_door->x = x;
	new_door->y = y;
	new_door->next = NULL;
	if (!src->door)
		src->door = new_door;
	else
	{
		tmp = src->door;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_door;
	}
}
