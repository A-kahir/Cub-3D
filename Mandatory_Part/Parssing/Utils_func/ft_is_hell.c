/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_hell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:14:27 by akahir            #+#    #+#             */
/*   Updated: 2025/09/10 17:34:42 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	ft_is_hell(t_source *src)
{
	t_source	*curr;

	printf("HELL is selected\n");
	curr = src;
	while (curr)
	{
		if (ft_strcmp(curr->var, "NO") == 0 && curr->value)
			curr->value = "Parssing/texture/HELL/NO_hell.xpm";
		else if (ft_strcmp(curr->var, "SO") == 0 && curr->value)
			curr->value = "Parssing/texture/HELL/SO_hell.xpm";
		else if (ft_strcmp(curr->var, "WE") == 0 && curr->value)
			curr->value = "Parssing/texture/HELL/WE_hell.xpm";
		else if (ft_strcmp(curr->var, "EA") == 0 && curr->value)
			curr->value = "Parssing/texture/HELL/EA_hell.xpm";
		curr->colors->hexa_rgb_f = 0x940909;
		curr->colors->hexa_rgb_c = 0x000000;
		curr = curr->next;
	}
}
