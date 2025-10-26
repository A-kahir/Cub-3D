/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_spaces_in_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:46:25 by akahir            #+#    #+#             */
/*   Updated: 2025/10/23 12:07:54 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

static int	ft_len(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && ft_is_spaces(str[i]) == 0)
		i++;
	j = ft_strlen(str) - 1;
	while (j >= 0 && ft_is_spaces(str[j]) == 0)
		j--;
	if (j < i)
		return (0);
	return (j - i + 1);
}

int	ft_max_len(t_source *src)
{
	int	max;
	int	temp;
	int	i;

	if (!src->map)
		return (0);
	max = 0;
	i = 0;
	while (src && src->map && src->map[i])
	{
		temp = ft_len(src->map[i]);
		if (temp > max)
			max = temp;
		i++;
	}
	return (max);
}

void	ft_add_spaces_in_map(t_source *src)
{
	int		i;
	int		j;
	int		max;
	char	*new_row;
	int		len;

	max = ft_max_len(src);
	i = -1;
	while (src && src->map && src->map[++i])
	{
		len = ft_strlen(src->map[i]);
		if (len < max)
		{
			new_row = (char *)malloc_cl(sizeof(char) * (max + 1), 0);
			j = -1;
			while (src->map[i][++j])
				new_row[j] = src->map[i][j];
			while (j < max)
				new_row[j++] = ' ';
			new_row[j] = '\0';
			src->map[i] = new_row;
			len++;
		}
	}
}
