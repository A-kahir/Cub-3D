/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:37:19 by akahir            #+#    #+#             */
/*   Updated: 2025/08/15 17:37:39 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

void	print_message(int flag)
{
	if (flag == 0)
	{
		write(2, "invalid Args\n", 14);
		return ;
	}
	if (flag == 1)
	{
		write(2, "Error: check your file .cub\n", 29);
		return ;
	}
	return ;
}
