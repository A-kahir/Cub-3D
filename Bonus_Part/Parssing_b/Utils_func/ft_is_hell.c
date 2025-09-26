/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_hell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:14:27 by akahir            #+#    #+#             */
/*   Updated: 2025/09/23 18:43:27 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	ft_is_hell(t_source *src)
{
	t_source	*curr;

	printf("HELL is selected\n");
	curr = src;
	while (curr)
	{
		if (ft_strcmp(curr->var, "NO") == 0 && curr->value)
			curr->value = "Parssing_l/texture/HELL/NO_hell.xpm";
		else if (ft_strcmp(curr->var, "SO") == 0 && curr->value)
			curr->value = "Parssing_l/texture/HELL/SO_hell.xpm";
		else if (ft_strcmp(curr->var, "WE") == 0 && curr->value)
			curr->value = "Parssing_l/texture/HELL/WE_hell.xpm";
		else if (ft_strcmp(curr->var, "EA") == 0 && curr->value)
			curr->value = "Parssing_l/texture/HELL/EA_hell.xpm";
		else if (ft_strcmp(curr->var, "F") == 0 && curr->colors)
			curr->colors->hexa_rgb_f = 610000;
		else if (ft_strcmp(curr->var, "C") == 0 && curr->colors)
			curr->colors->hexa_rgb_c = 161616;
		curr = curr->next;
	}
}
