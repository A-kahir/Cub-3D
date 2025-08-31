/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:47:54 by akahir            #+#    #+#             */
/*   Updated: 2025/08/21 01:47:54 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_source	*ft_fill_struct(t_source *src, char *line)
{
	char	**var;
	char	**value;
	int		len;
	int		i;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	i = 0;
	while (line[i])
	{
		if (line[len - 2] == '\r')
			line[len - 2] = '\0';
		i++;
	}
	var = ft_split(line, ' ');
	if (!var)
		return (perror("split"), NULL);
	value = ft_split(var[1], '\n');
	if (!value || !value[0])
		return (src);
	if (var && (!ft_strncmp(var[0], "NO", 2) || !ft_strncmp(var[0], "SO", 2)
			|| !ft_strncmp(var[0], "WE", 2) || !ft_strncmp(var[0], "WE", 2)
			|| !ft_strncmp(var[0], "EA", 2)))
	{
		src = ft_add_back(src, var[0], value[0]);
	}
	else if (!ft_strcmp(var[0], "F") || !ft_strcmp(var[0], "C"))
	{
		char *rgb_str = NULL;
		i = 1;
		while (var[i])
		{
			if (!rgb_str)
				rgb_str = ft_strdup(var[i], 0);
			else
			{
				char *tmp = rgb_str;
				rgb_str = ft_strjoin(rgb_str, var[i]);
				free(tmp);
			}
			i++;
		}
		src = ft_add_back(src, var[0], rgb_str);
	}
	return (src);
}
