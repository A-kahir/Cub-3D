/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:15:57 by akahir            #+#    #+#             */
/*   Updated: 2025/08/30 21:17:06 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static	int	over_flow(int signe)
{
	if (signe == 1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(char *str)
{
	int i;
	int signe;
	int result;

	signe = 1;
	i = 0;
	result = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (2147483647 - (str[i] - '0')) / 10)
			return (over_flow(signe));
		result = ((result * 10) + (str[i] - '0'));
		i++;
	}
	return (result * signe);
}
