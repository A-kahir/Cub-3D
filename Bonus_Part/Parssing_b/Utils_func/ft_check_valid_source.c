/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_source.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:57:33 by akahir            #+#    #+#             */
/*   Updated: 2025/09/09 16:57:33 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

int	ft_chack_valid_source(t_source *src, char *str)
{
	t_source	*curr;

	if (!str)
		return (-1);
	curr = src;
	while (curr)
	{
		if (!ft_strncmp(curr->var, str, 2) || !ft_strncmp(curr->var, str, 1))
			return (print_message(17, NULL, '\0'), malloc_cl(0, 1), -1);
		curr = curr->next;
	}
	if (ft_is_spaces(str[0]) == 0)
		return (-1);
	if (str[0] == '\n' || str[0] == '\0')
		return (-1);
	return (0);
}
