/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_door_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 23:05:49 by akahir            #+#    #+#             */
/*   Updated: 2025/10/19 18:58:02 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

int	ft_check_struct_with_flag_map(t_source *src, char *check)
{
	t_source *curr;

	curr = src;
	while (curr)
	{
		if (curr->var && check && ft_strcmp(curr->var, check) == 0)
			return (0);
		curr = curr->next;
	}
	return (-1);
}



void	ft_add_door(t_source *src, int x, int y, int index)
{
	t_doors	*new_door;
	t_doors	*tmp;

	new_door = malloc_cl(sizeof(t_doors), 0);
	if (!new_door)
		return ;
	new_door->index = index;
	new_door->x = x;
	new_door->y = y;
	new_door->etat = 1;
	new_door->p_ouvert = 0.0;
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

void	ft_add_sprites(t_source *src, int x, int y, int index)
{
	t_sprites *new_sprite;
	t_sprites *tmp;

	new_sprite = malloc_cl(sizeof(t_sprites), 0);
	if (!new_sprite)
		return ;
	new_sprite->index = index;
	new_sprite->x = x;
	new_sprite->y = y;
	new_sprite->etat = 1;
	new_sprite->p_ouvert = 0.0;
	new_sprite->timer = 0.0;
	new_sprite->next = NULL;
	if (!src->sprites)
		src->sprites = new_sprite;
	else
	{
		tmp = src->sprites;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_sprite;
	}
}
