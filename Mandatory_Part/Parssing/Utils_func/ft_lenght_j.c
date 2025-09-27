/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght_j.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:22:22 by akahir            #+#    #+#             */
/*   Updated: 2025/09/27 18:29:02 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

int	ft_lenght_j(t_source *src)
{
	t_source	*curr;
	int			i;
	int			j;

	i = 0;
	j = -1;
	curr = src;
	while (curr->map[i])
	{
		j++;
		i++;
	}
	return (j);
}

int	check_args1(t_source *src)
{
	int			count;
	t_source	*curr;

	count = 0;
	curr = src;
	while (curr)
	{
		if (count > 6)
			break ;
		count++;
		curr = curr->next;
	}
	if (count == 6)
		return (0);
	return (-1);
}
