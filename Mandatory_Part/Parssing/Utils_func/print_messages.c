/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:37:19 by akahir            #+#    #+#             */
/*   Updated: 2025/08/21 15:06:14 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

void ft_cantinue2(int flag, char *arg, char ch)
{
	(void)arg;
	if (flag == 5)
	{
		write(2, "You have error before Map\n", 27);
		return ;
	}
	else if (flag == 6)
	{
		write(2, "check your Map: You have invalid character: [", 46);
		write(2, &ch, 1);
		write(2, "]", 2);
		write(2, " from the Last line Map", 24);
		write(2, "\n", 2);
		return ;
	}
	else if (flag == 7)
	{
		write(2, "check your Map: You have invalid character: [", 46);
		write(2, &ch, 1);
		write(2, "]", 2);
		write(2, " from the Last line [", 22);
		write(2, arg, ft_strlen(arg));
		write(2, "]\n", 3);
	}
}

void ft_cantinue1(int flag, char *arg, char ch)
{
	if (flag == 3)
	{
		write(2, "check your Map: You have invalid character: [", 46);
		write(2, &ch, 1);
		write(2, "]", 2);
		write(2, " from the line Map: [", 22);
		write(2, arg, ft_strlen(arg));
		write(2, "].\n", 4);
		return ;
	}
	else if (flag == 4)
	{
		write(2, "check your Map: You have invalid character: [", 46);
		write(2, &ch, 1);
		write(2, "]", 2);
		write(2, " from the line Map: [", 22);
		write(2, arg, ft_strlen(arg) - 2);
		write(2, "].\n", 4);
		return ;
	}
	else
		ft_cantinue2(flag, arg, ch);
}

void	print_message(int flag, char *arg, char ch)
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
	if (flag == 2)
	{
		write(2, "check your Map: You have invalid character: [", 46);
		write(2, &ch, 1);
		write(2, "]", 2);
		write(2, " from the first line Map.\n", 27);
		return ;
	}
	ft_cantinue1(flag, arg, ch);
	return ;
}
