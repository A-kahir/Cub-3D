/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:23:38 by akahir            #+#    #+#             */
/*   Updated: 2025/08/31 16:23:38 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	init_new_node(t_source *new_node)
{
	new_node->mlx_image = 0;
	new_node->mlx_pointer = 0;
	new_node->mlx_window = 0;
	new_node->colors->hexa_rgb_f = 0;
	new_node->colors->hexa_rgb_c = 0;
	new_node->p = malloc_cl(sizeof(t_player), 0);
	if (!new_node->p)
		return ;
	new_node->p->p_px = 0;
	new_node->p->p_py = 0;
	new_node->p->p_or = '\0';
	new_node->door = malloc_cl(sizeof(t_doors), 0);
	if (!new_node->door)
		return ;
	new_node->door->x = 0;
	new_node->door->y = 0;
	new_node->door = NULL;
	new_node->next = NULL;
}

t_source	*ft_add_back(t_source *line, char *var, char *value)
{
	t_source	*new_node;
	t_source	*curr;

	new_node = malloc_cl(sizeof(t_source), 0);
	if (!new_node)
		return (line);
	new_node->var = ft_strdup(var, 0);
	if (value != NULL)
		new_node->value = ft_strdup(value, 0);
	else
		new_node->value = NULL;
	new_node->colors = malloc_cl(sizeof(t_colors), 0);
	if (!new_node->colors)
		return (line);
	init_new_node(new_node);
	if (!line)
		return (new_node);
	curr = line;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
	return (line);
}
