/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:28:06 by akahir            #+#    #+#             */
/*   Updated: 2025/09/01 16:39:31 by akahir           ###   ########.fr       */
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
	int save_pos;

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
					if (!(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13)) && i == 0)
						return (print_message(2, src->map[i], src->map[i][l]), -1);
					else if (!(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13)) && i == len_j)
						return (print_message(7, src->map[i], src->map[i][l]), -1);
				}
				l++;
			}
		}
		if (i > 0 && j == 0)
		{
			printf("222222222222222\n");
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
					if (l == 0 && src->map[i][l] != '1'
						&& ((src->map[i][l + 1] || src->map[i][l - 1]) != (src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13))))
					{
						if (!(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13) || (src->map[i][l] == 'N') || (src->map[i][l] == 'S')))
						{
							return (print_message(4, src->map[i], src->map[i][l]), -1);
						}
					}
					else if ((src->map[i][l + 1] == 32 || (src->map[i][l + 1] >= 9 && src->map[i][l + 1] <= 13)))
					{
						if (src->map[i][l] != '1' && !(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13)))
						{
							return (print_message(4, src->map[i], src->map[i][l]), -1);
						}
					}
					else if (l > 0 && (src->map[i][l - 1] == 32 || (src->map[i][l - 1] >= 9 && src->map[i][l - 1] <= 13)))
					{
						if (src->map[i][l] != '1' && !(src->map[i][l] == 32 || (src->map[i][l] >= 9 && src->map[i][l] <= 13)))
						{
							return (print_message(4, src->map[i], src->map[i][l]), -1);
						}
					}
					else if (l == len_i)
					{
						if (src->map[i][l] != '1')
						{
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
							return (print_message(4, src->map[i], src->map[i][save_pos]), -1);
						}
						else if ((src->map[i - 1][save_pos] == 32 || (src->map[i - 1][save_pos] >= 9 && src->map[i - 1][save_pos] <= 13)))
						{
							return (print_message(4, src->map[i], src->map[i][save_pos]), -1);
						}
					}
				}
				l++;
			}
		}
		i++;
		j++;
	}
	i = 0;
	while (src->map[i])
	{
		j = 0;
		save_pos = 0;
		while (src->map[i][j] != '\0')
		{
			if (i < len_j && (src->map[i][j] == 32 || (src->map[i][j] >= 9 && src->map[i][j] <= 13)))
			{
				save_pos = j;
				if (!(src->map[i + 1][save_pos] == 32 || (src->map[i + 1][save_pos] >= 9 && src->map[i + 1][save_pos] <= 13)) && src->map[i + 1][save_pos] != '1')
				{
					return (print_message(4, src->map[i + 1], src->map[i + 1][save_pos]), -1);
				}
				else if (i > 0 && !(src->map[i - 1][save_pos] == 32 || (src->map[i - 1][save_pos] >= 9 && src->map[i - 1][save_pos] <= 13)) && src->map[i - 1][save_pos] != '1')
				{
					return (print_message(4, src->map[i - 1], src->map[i - 1][save_pos]), -1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
