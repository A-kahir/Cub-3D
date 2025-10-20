/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_hell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 19:10:27 by akahir            #+#    #+#             */
/*   Updated: 2025/10/20 15:45:30 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	ft_is_hell(t_source *src)
{
	t_source	*curr;

	printf("HELL is selected\n");
	curr = src;
	while (curr)
	{
		if (ft_strcmp(curr->var, "NO") == 0 && curr->value)
			curr->value = "Bonus_Part/Parssing_b/texture/HELL/NO_hell.xpm";
		else if (ft_strcmp(curr->var, "SO") == 0 && curr->value)
			curr->value = "Bonus_Part/Parssing_b/texture/HELL/SO_hell.xpm";
		else if (ft_strcmp(curr->var, "WE") == 0 && curr->value)
			curr->value = "Bonus_Part/Parssing_b/texture/HELL/WE_hell.xpm";
		else if (ft_strcmp(curr->var, "EA") == 0 && curr->value)
			curr->value = "Bonus_Part/Parssing_b/texture/HELL/EA_hell.xpm";
		else if (ft_strcmp(curr->var, "DR") == 0 && curr->value)
			curr->value = "Bonus_Part/Parssing_b/texture/HELL/DR_hell.xpm";
		else if (ft_strcmp(curr->var, "S") == 0 && curr->value)
			curr->value = "Bonus_Part/Parssing_b/texture/HELL/S_hell.xpm";
		curr->colors->hexa_rgb_f = 0x610000;
		curr->colors->hexa_rgb_c = 0x161616;
		curr = curr->next;
	}
}
