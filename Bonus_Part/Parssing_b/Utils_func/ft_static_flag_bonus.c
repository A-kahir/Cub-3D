/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:13:41 by akahir            #+#    #+#             */
/*   Updated: 2025/10/29 07:29:50 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

int	ft_static_flag(int new_nb, int flag)
{
	static int	save_nb;

	if (flag == 1)
		save_nb = new_nb;
	return (save_nb);
}
