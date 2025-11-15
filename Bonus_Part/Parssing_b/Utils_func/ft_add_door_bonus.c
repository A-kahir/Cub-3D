/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_door_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 23:05:49 by akahir            #+#    #+#             */
/*   Updated: 2025/11/14 21:57:48 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	ft_add_door(t_source *src, int x, int y, int index)
{
	t_doors	*new_door;
	t_doors	*tmp;

	new_door = malloc_cl(sizeof(t_doors), 0);
	if (!new_door)
		return (ft_free_mlx(src), malloc_cl(0, 2), (void) NULL);
	new_door->index = index;
	new_door->x = x;
	new_door->y = y;
	new_door->etat = 1;
	new_door->timer = 0.0;
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
