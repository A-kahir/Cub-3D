/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:15:12 by ifaleh            #+#    #+#             */
/*   Updated: 2025/10/29 07:46:13 by ifaleh           ###   ########.fr       */
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

static void	norm_doors(t_doors *curr, t_source *src)
{
	if (curr->etat == 1 && curr->p_ouvert < 1.0)
	{
		curr->timer = src->frame_time;
		curr->p_ouvert = curr->timer / 1.0;
		if (curr->p_ouvert >= 1.0)
		{
			curr->p_ouvert = 1.0;
			curr->timer = 0.0;
		}
	}
	else if (curr->etat == 0 && curr->p_ouvert > 0.0)
	{
		curr->timer += src->frame_time;
		curr->p_ouvert = 1.0 - (curr->timer / 1.0);
		if (curr->p_ouvert <= 0.0)
		{
			curr->p_ouvert = 0.0;
			curr->timer = 0.0;
		}
	}
}

void	update_door_animation(t_source *src)
{
	t_doors	*curr;

	curr = src->door;
	while (curr)
	{
		norm_doors(curr, src);
		curr = curr->next;
	}
}
