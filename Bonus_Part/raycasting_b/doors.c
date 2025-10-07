/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:15:12 by ifaleh            #+#    #+#             */
/*   Updated: 2025/10/07 02:38:25 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int	ft_door(t_source *src, int mapx, int mapy)
{
	t_doors	*current;

	if (!src || !src->door)
		return (-1);
	current = src->door;
	while (current)
	{
		if (current->x == mapx && current->y == mapy)
			return (current->index);
		current = current->next;
	}
	return (-1);
}

int	door_state(t_source *src, int index)
{
	t_doors	*current;

	if (!src || !src->door)
		return (0);
	current = src->door;
	while (current)
	{
		if (current->index == index)
			return (current->etat);
		current = current->next;
	}
	return (0);
}

// void	update_door_animatioon(t_source *src)
// {
// 	t_doors	*curr;
	
// 	curr = src->door;
// 	while (curr)
// 	{
		
// 	}
// }
