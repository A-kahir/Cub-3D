/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:13:41 by akahir            #+#    #+#             */
/*   Updated: 2025/09/27 22:13:54 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

int	ft_static_flag(int new_nb, int flag)
{
	static int save_nb;

	if (flag == 1)
		save_nb = new_nb;
	return (save_nb);
}
