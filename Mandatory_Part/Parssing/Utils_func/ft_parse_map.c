/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:28:06 by akahir            #+#    #+#             */
/*   Updated: 2025/09/07 19:12:49 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void ft_debug_map(char *map, int pos)
{
	int i = 0;
	while (pos > i)
	{
		printf(" ");
		i++;
	}
	printf("i\n");
	printf("%s\n\n", map);
}


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
	return (j);
}

int	ft_parse_map(t_source *src)
{
	int l;
	int i;
	int len_i;
	int j;
	int len_j;
	int save_pos;

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
					if (!(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13)) && i == 0)
						return (print_message(2, src->map[i], src->map[i][l]), -1);
					else if (!(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13)) && i == len_j)
						return (print_message(7, src->map[i], src->map[i][l]), -1);
				}
				l++;
			}
		}
		if (i > 0 && len_j > i)
		{
			l = 0;
			while (src->map[i][l] != '\0')
			{
				if (src->map[i][l] == '0')
				{
					if (src->map[i - 1][l - 1] != '1' && src->map[i][l - 1] == '1' && src->map[i - 1][l] == '1')
						return (print_message(4, src->map[i],src->map[i][l]), -1);
					else if (src->map[i + 1][l + 1] != '1' && src->map[i + 1][l] == '1' && src->map[i][l + 1] == '1')
						return (print_message(4, src->map[i],src->map[i][l]), -1);
					else if (src->map[i + 1][l - 1] != '1' && src->map[i + 1][l] == '1' && src->map[i][l - 1] == '1')
						return (print_message(4, src->map[i],src->map[i][l]), -1);
					else if (src->map[i - 1][l + 1] != '1' && src->map[i - 1][l] == '1' && src->map[i][l + 1] == '1')
						return (print_message(4, src->map[i],src->map[i][l]), -1);
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
					if (l == 0 && src->map[i][l] != '1'
						&& ((src->map[i][l + 1] || src->map[i][l - 1]) != (src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13))))
					{
						if (!(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13) || (src->map[i][l] == 'N') || (src->map[i][l] == 'S')))
						{
							printf("1\n");
							return (print_message(4, src->map[i], src->map[i][l]), -1);
						}
					}
					else if ((src->map[i][l + 1] == 32 || (src->map[i][l + 1] >= 9 && src->map[i][l + 1] <= 13)))
					{
						if (src->map[i][l] != '1' && !(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13)))
						{
							printf("2\n");
							return (print_message(4, src->map[i], src->map[i][l]), -1);
						}
					}
					else if (l > 0 && (src->map[i][l - 1] == 32 || (src->map[i][l - 1] >= 9 && src->map[i][l - 1] <= 13)))
					{
						if (src->map[i][l] != '1' && !(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13)))
						{
							printf("3\n");
							return (print_message(4, src->map[i], src->map[i][l]), -1);
						}
					}
					else if (l == len_i)
					{
						if (src->map[i][l] != '1')
						{
							printf("4\n");
							return (print_message(4, src->map[i], src->map[i][l]), -1);
						}
					}
				}
				l++;
			}
		}
		if (i > 0 && len_j > i && ((src->map[i + 1][0] == 32 || (src->map[i + 1][0] >= 9 && src->map[i + 1][0] <= 13)
			|| ((src->map[i - 1][0] == 32 || (src->map[i - 1][0] >= 9 && src->map[i - 1][0] <= 13))))))
		{
			l = 0;
			while (src->map[i][l] != '\0')
			{
				save_pos = 0;
				if (src->map[i][l] != '1' && !(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13)))
				{
					if (l > 0 && src->map[i][l - 1] == '1' && src->map[i][l + 1] == '1')
					{
						save_pos = l;
						if ((src->map[i + 1][save_pos] == 32 || (src->map[i + 1][save_pos] >= 9 && src->map[i + 1][save_pos] <= 13)))
						{
							printf("5\n");
							return (print_message(4, src->map[i], src->map[i][save_pos]), -1);
						}
						else if ((src->map[i - 1][save_pos] == 32 || (src->map[i - 1][save_pos] >= 9 && src->map[i - 1][save_pos] <= 13)))
						{
							printf("6\n");
							return (print_message(4, src->map[i], src->map[i][save_pos]), -1);
						}
					}
				}
				l++;
			}
		}
		if (i != 0 && i != len_j)
		{
			l = 1;
			while (src->map[i][l + 1] != '\0')
			{
				if (src->map[i][l] != '0' && src->map[i][l] != '1'
					&& !(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13))
					&& !(src->map[i][l] == 'N' || src->map[i][l] == 'S'))
				{
					return (print_message(4, src->map[i], src->map[i][l]), -1);
				}
				l++;
			}
		}
		i++;
		j++;
	}
	i = 1;
	l = 0;
	while (src->map[i])
	{
		l = 0;
		while (src->map[i][l] != '\0')
		{
			if (l > 0 && len_j > i)
			{
				if (src->map[i][l] == '0')
				{
					if ((src->map[i - 1][l] == 32 || (src->map[i - 1][l] >= 9 && src->map[i - 1][l] <= 13))
						|| src->map[i + 1][l] == 32 || (src->map[i + 1][l] >= 9 && src->map[i + 1][l] <= 13))
					{
						printf("####\n");
						return (print_message(4, src->map[i], src->map[i][l]), -1);
					}
				}
			}
			l++;
		}
		i++;
	}
	return (0);
}
