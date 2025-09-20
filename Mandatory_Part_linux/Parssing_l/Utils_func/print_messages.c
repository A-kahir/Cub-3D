/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:37:19 by akahir            #+#    #+#             */
/*   Updated: 2025/09/19 18:28:56 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

void	ft_cantinue4(int flag)
{
	if (flag == 12)
	{
		write(2, "Your Texture is invalid for MLX.❌\n", 37);
		return ;
	}
}

void	ft_cantinue3(int flag)
{
	if (flag == 8)
	{
		write(2, "Make sure you have only One Player👤\n", 40);
		return ;
	}
	if (flag == 9)
	{
		write(2, "Make sure you have Player 👤\n", 32);
		return ;
	}
	if (flag == 10)
	{
		write(2, "value of colors incorrect. ❌\n", 32);
		return ;
	}
	if (flag == 11)
	{
		write(2, "You should respect RGB range.\n", 31);
		return ;
	}
	ft_cantinue4(flag);
}

void	ft_cantinue2(int flag, char *arg, char ch)
{
	if (flag == 5)
	{
		write(2, "You have error before Map ❌.\n", 32);
		return ;
	}
	else if (flag == 6)
	{
		write(2, "check your Map: You have invalid character: [", 46);
		write(2, &ch, 1);
		write(2, "]", 2);
		write(2, " from the Last line Map ❌.", 29);
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
		write(2, "].❌\n", 7);
	}
	ft_cantinue3(flag);
}

void	ft_cantinue1(int flag, char *arg, char ch)
{
	if (flag == 3)
	{
		write(2, "Error : MLX System call failed\n", 32);
		return ;
	}
	if (flag == 4)
	{
		write(2, "check your Map: You have invalid character: [", 46);
		write(2, &ch, 1);
		write(2, "]", 2);
		write(2, " from the line Map: [", 22);
		write(2, arg, ft_strlen(arg));
		write(2, "].❌\n", 7);
		return ;
	}
	else
		ft_cantinue2(flag, arg, ch);
}

void	print_message(int flag, char *arg, char ch)
{
	if (flag == 0)
	{
		write(2, "invalid Args ❌\n", 18);
		return ;
	}
	if (flag == 1)
	{
		write(2, "Error: check your file .cub ❌\n", 33);
		return ;
	}
	if (flag == 2)
	{
		write(2, "check your Map: You have invalid character: [", 46);
		write(2, &ch, 1);
		write(2, "]", 2);
		write(2, " from the first line Map. ❌\n", 31);
		return ;
	}
	ft_cantinue1(flag, arg, ch);
	return ;
}
