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

#include "../cub_bonus.h"

int	ft_chack_valid_source(char *str)
{
	if (!str)
		return (-1);
	if (ft_is_spaces(str[0]) == 0)
		return (-1);
	if (str[0] == '\n' || str[0] == '\0')
		return (-1);
	return (0);
}
