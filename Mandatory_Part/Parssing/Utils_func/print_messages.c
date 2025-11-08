/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:37:19 by akahir            #+#    #+#             */
/*   Updated: 2025/11/07 15:56:25 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

void	ft_cantinue3(int flag)
{
	if (flag == 8)
		return (write(2, "Make sure you have only One Player👤\n", 40),
			(void) NULL);
	if (flag == 9)
		return (write(2, "Make sure you have Player 👤\n", 32), (void) NULL);
	if (flag == 10)
		return (write(2, "value of colors incorrect. ❌\n", 32), (void) NULL);
	if (flag == 11)
		return (write(2, "You should respect RGB range.\n", 31), (void) NULL);
}

void	ft_cantinue2(int flag, char *arg, char ch)
{
	if (flag == 5)
		return (write(2, "You have error before Map ❌.\n", 32), (void) NULL);
	else if (flag == 6)
		return (write(2, "check your Map: You have invalid character: [", 46),
			write(2, &ch, 1), write(2, "]", 2),
			write(2, " from the Last line Map ❌.", 29),
			write(2, "\n", 2), (void) NULL);
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
	static int	flag_error;

	if (flag_error == 0)
	{
		write(2, "Error :\n", 9);
		flag_error = 1;
	}
	if (flag == 0)
		return (write(2, "invalid Args ❌\n", 18), (void) NULL);
	if (flag == 1)
		return (write(2, "Error: check your file .cub ❌\n", 33), (void) NULL);
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
