/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:49:15 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/04 16:47:48 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

int	ft_static_flag(int new_nb, int flag)
{
	static int	save_nb;

	if (flag == 1)
		save_nb = new_nb;
	return (save_nb);
}
