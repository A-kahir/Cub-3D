/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:17:57 by akahir            #+#    #+#             */
/*   Updated: 2025/08/21 15:22:39 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

int ft_if_valid_map(char *line, int i)
{
	static int save_line;
	int len;

	1 && (len = ft_strlen(line) - 1);
	while (line[i] != '\0')
	{
		if (line[i + 1] == 32 || (line[i + 1] >= 9 && line[i + 1] <= 13))
		{
			while (line[i] == 32 || (line[i] >= 9 && line[i] <= 13))
				i++;
			if (line[i] != '1')
				return (print_message(7, line, line[i]), -1);
		}
		else if (!(line[i + 1] == 32 || (line[i + 1] >= 9 && line[i + 1] <= 13)))
		{
			while (line[i] == '0')
				i++;
			if (line[i] != '1' && line[i] != 'S' && line[i] != 'N' && line[i] != 'W' && line[i] != 'E')
				return (print_message(4, line, line[i]), -1);
		}
		if (save_line == 0 && line[i] != '1')
		{
			if (!(line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
				return (print_message(2, NULL, line[i]), -1);
		}
		else if (save_line > 0)
		{
			if (line[0] != '1')
            {
				if (!(line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
					return (print_message(4, line, line[0]), -1);
            }
			else if (line[len] != '1')
				if (!(line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
					return (print_message(3, line, line[len]), -1);
		}
		i++;
	}
	return (save_line++, 0);
}
