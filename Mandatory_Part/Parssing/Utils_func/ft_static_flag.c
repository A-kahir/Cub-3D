/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:49:15 by ifaleh            #+#    #+#             */
/*   Updated: 2025/10/31 18:25:49 by ifaleh           ###   ########.fr       */
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

