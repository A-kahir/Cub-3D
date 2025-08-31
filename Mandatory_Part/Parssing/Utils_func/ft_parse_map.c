/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:28:06 by akahir            #+#    #+#             */
/*   Updated: 2025/08/31 20:48:49 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int ft_lenght_j(t_source *src)
{
	t_source *curr;
	int i;
	int j;

	i = 0;
	j = -1;
	curr = src;
	while (curr->map[i])
	{
		j++;
		i++;
	}
	printf("len_j ===> %d\n\n", j);
	return (j);
}

int	ft_parse_map(t_source *src)
{
	int p; // debug
	int l;
	int i;
	int len_i;
	int j;
	int len_j;

	p = 0;
	while (src->map[p])
	{
		printf("%s\n", src->map[p]);
		p++;
	}
	printf("\n\n");
	i = 0;
	l = 0;
	len_j = ft_lenght_j(src);
	j = 0;
	while (src->map[i])
	{
		len_i = ft_strlen(src->map[i]) - 1;
		if (i == 0 || i == len_j)
		{
			l = 0;
			while (src->map[i][l])
			{
				if (src->map[i][l] != '1')
				{
					if (!(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13)))
						return (print_message(2, src->map[i], src->map[i][l]), -1);
				}
				l++;
			}
		}
		if (i > 0 && j == 0)
		{
			l = 0;
			while (src->map[l])
			{
				if (src->map[l][0] != '1' || src->map[l][len_i] != '1')
				{
					if (!(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13)))
						return (print_message(4, src->map[l], src->map[l][0]), -1);
				}
				l++;
			}
		}
		if (i > 0)
		{
			l = 0;
			while (src->map[i][l] != '\0')
			{
				if (src->map[i][l])
				{
					if (src->map[i][l] != '0' && src->map[i][l] != '1')
					{
						if (!(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13))
							|| !(src->map[i][l] != 'N' || src->map[i][l] != 'S'))
						{
							printf("******************************************????????????????????????\n");
							return (print_message(4, src->map[i], src->map[i][l]), -1);
						}
					}
				}
				l++;
			}
		}
		printf("\ni ===> %d\n", i);
		printf("j ===> %d\n", j);
		i++;
		j++;
	}
	return (0);
}
