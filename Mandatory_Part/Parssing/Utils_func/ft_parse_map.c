/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:28:06 by akahir            #+#    #+#             */
/*   Updated: 2025/09/23 01:58:00 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

void	ft_debug_map(char *map, int pos)
{
	int	i;

	i = 0;
	while (pos > i)
	{
		printf(" ");
		i++;
	}
	printf("i\n");
	printf("%s\n\n", map);
}

int	ft_lenght_j(t_source *src)
{
	t_source	*curr;
	int			i;
	int			j;

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

static int	ft_check_first_last_row(t_source *src, int i, int len_j)
{
	int	l;

	l = 0;
	while (src->map[i][l])
	{
		if (src->map[i][l] != '1')
		{
			if (ft_is_spaces(src->map[i][l]) == -1 && i == 0)
				return (print_message(2, src->map[i], src->map[i][l]), -1);
			else if (ft_is_spaces(src->map[i][l]) == -1 && i == len_j)
				return (ft_debug_map(src->map[i], l),
					print_message(7, src->map[i], src->map[i][l]), -1);
		}
		l++;
	}
	return (0);
}

static char	ft_check(t_source *src, int r, int c)
{
	if (r < 0 || r >= src->height)
		return (' ');
	if (!src->map[r])
		return (' ');
	if (c < 0 || c >= (int)ft_strlen(src->map[r]))
		return (' ');
	if (src->map[r][c] == '0' || src->map[r][c] == '1'
		|| src->map[r][c] == 'N' || src->map[r][c] == 'S'
		|| src->map[r][c] == 'E' || src->map[r][c] == 'W')
		return (src->map[r][c]);
	return (' ');
}

static int	check_corner_and_side(t_source *src, int i, int l)
{
	char curr;
	
	curr = ft_check(src, i, l);
	if (curr == '0' || curr == 'N' || curr == 'S' || curr == 'E' || curr == 'W')
	{
		if (ft_check(src, i - 1, l - 1) == ' ')
			return (-1);
		if (ft_check(src, i + 1, l + 1) == ' ')
			return (-1);
		if (ft_check(src, i + 1, l - 1) == ' ')
			return (-1);
		if (ft_check(src, i - 1, l + 1) == ' ')
			return (-1);
		if (ft_check(src, i - 1, l) == ' ')
			return (-1);
		if (ft_check(src, i + 1, l) == ' ')
			return (-1);
		if (ft_check(src, i, l - 1) == ' ')
			return (-1);
		if (ft_check(src, i, l + 1) == ' ')
			return (-1);
	}
	return (0);
}

static int	ft_check_corners(t_source *src, int i, int l)
{
	if (check_corner_and_side(src, i, l) == -1)
		return (ft_debug_map(src->map[i], l), 
			print_message(4, src->map[i], src->map[i][l]), -1);
	return (0);
}

static int	ft_check_middle_chars(t_source *src, int i, int len_j)
{
	int	l;

	if (i <= 0 || len_j <= i)
		return (0);
	l = 0;
	while (src->map[i][l] != '\0')
	{
		if (src->map[i][l] == '0' || (src->map[i][l] == 'N'
			|| src->map[i][l] == 'S' || src->map[i][l] == 'E' 
			|| src->map[i][l] == 'W'))
		{
			if (ft_check_corners(src, i, l) == -1)
				return (-1);
		}
		l++;
	}
	return (0);
}

static int	ft_check_spaces_zone(t_source *src, int i, int l, int len_i)
{
	if (ft_is_spaces(src->map[i][l + 1]) == 0)
	{
		if (src->map[i][l] != '1' && !(ft_is_spaces(src->map[i][l]) == 0))
			return (ft_debug_map(src->map[i], l), 
				print_message(4, src->map[i], src->map[i][l]), -1);
	}
	else if (l > 0 && ft_is_spaces(src->map[i][l - 1]) == 0)
	{
		if (src->map[i][l] != '1' && !(ft_is_spaces(src->map[i][l]) == 0))
			return (ft_debug_map(src->map[i], l), 
				print_message(4, src->map[i], src->map[i][l]), -1);
	}
	else if (l == len_i)
	{
		if (src->map[i][l] != '1')
			if (ft_is_spaces(src->map[i][l]) == -1)
				return (ft_debug_map(src->map[i], l), 
					print_message(4, src->map[i], src->map[i][l]), -1);
	}
	return (0);
}

static int	ft_check_cadring_map(t_source *src, int i, int len_i)
{
	int	l;

	l = 0;
	while (src->map[i][l] != '\0')
	{
		if (src->map[i][l])
		{
			if (l == 0 && src->map[i][l] != '1'
				&& ((src->map[i][l + 1] || src->map[i][l - 1]) 
				!= (ft_is_spaces(src->map[i][l]) == 0)))
			{
				if (!(ft_is_spaces(src->map[i][l]) == 0
					|| (src->map[i][l] == 'N') || (src->map[i][l] == 'S')
					|| (src->map[i][l] == 'W') || (src->map[i][l] == 'E')))
					return (ft_debug_map(src->map[i], l), 
						print_message(4, src->map[i], src->map[i][l]), -1);
			}
			else if (ft_check_spaces_zone(src, i, l, len_i) == -1)
				return (-1);
		}
		l++;
	}
	return (0);
}

static int	ft_check_vertical_spaces(t_source *src, int i, int len_j)
{
	int	l;
	int	save_pos;

	if (i <= 0 || len_j <= i || !((ft_is_spaces(src->map[i + 1][0]) == 0)
		|| (ft_is_spaces(src->map[i - 1][0]) == 0)))
		return (0);
	l = 0;
	while (src->map[i][l] != '\0')
	{
		if (src->map[i][l] != '1' && ft_is_spaces(src->map[i][l]) == -1)
		{
			if (l > 0 && src->map[i][l - 1] == '1' && src->map[i][l + 1] == '1')
			{
				save_pos = l;
				if (ft_is_spaces(src->map[i + 1][save_pos]) == 0)
					return (ft_debug_map(src->map[i], l), 
						print_message(4, src->map[i], src->map[i][save_pos]), -1);
				else if (ft_is_spaces(src->map[i - 1][save_pos]) == 0)
					return (ft_debug_map(src->map[i], l), 
						print_message(4, src->map[i], src->map[i][save_pos]), -1);
			}
		}
		1 && (l++, save_pos = 0);
	}
	return (0);
}

static int	ft_valid_char_rows(t_source *src, int i, int len_j)
{
	int	l;

	if (i == 0 || i == len_j)
		return (0);
	l = 1;
	while (src->map[i][l + 1] != '\0')
	{
		if (src->map[i][l] != '0' && src->map[i][l] != '1'
			&& ft_is_spaces(src->map[i][l]) == -1
			&& !(src->map[i][l] == 'N' || src->map[i][l] == 'S'
			|| src->map[i][l] == 'E' || src->map[i][l] == 'W'))
			return (ft_debug_map(src->map[i], l), 
				print_message(4, src->map[i], src->map[i][l]), -1);
		l++;
	}
	return (0);
}

static int	ft_check_up_bottom_valid_chars(t_source *src, int len_j)
{
	int	i;
	int	l;

	i = 1;
	while (src->map[i])
	{
		l = 0;
		while (src->map[i][l] != '\0')
		{
			if (l > 0 && len_j > i)
				if (src->map[i][l] == '0'
					|| (src->map[i][l] == 'N' || src->map[i][l] == 'S'
					|| src->map[i][l] == 'E' || src->map[i][l] == 'W'))
					if ((ft_is_spaces(src->map[i - 1][l]) == 0)
						|| (ft_is_spaces(src->map[i + 1][l]) == 0))
						return (ft_debug_map(src->map[i], l), 
							print_message(4, src->map[i], src->map[i][l]), -1);
			l++;
		}
		i++;
	}
	return (0);
}

int	ft_parse_map(t_source *src)
{
	int	i;
	int	len_j;
	int	len_i;

	ft_add_spaces_in_map(src);
	1 && (len_j = ft_lenght_j(src), i = 0);
	while (src->map[i])
	{
		len_i = ft_strlen(src->map[i]) - 1;
		if (i == 0 || i == len_j)
		{
			if (ft_check_first_last_row(src, i, len_j) == -1)
				return (-1);
		}
		if (ft_check_middle_chars(src, i, len_j) == -1)
			return (-1);
		if (i > 0 && ft_check_cadring_map(src, i, len_i) == -1)
			return (-1);
		if (ft_check_vertical_spaces(src, i, len_j) == -1)
			return (-1);
		if (ft_valid_char_rows(src, i, len_j) == -1)
			return (-1);
		i++;
	}
	return (ft_check_up_bottom_valid_chars(src, len_j));
}
