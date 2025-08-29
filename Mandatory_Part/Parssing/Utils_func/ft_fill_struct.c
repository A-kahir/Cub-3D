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

#include "../../parsing.h"

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
			|| !ft_strncmp(var[0], "EA", 2) || !ft_strcmp(var[0], "F")
			|| !ft_strcmp(var[0], "C")))
	{
		src = ft_add_back(src, var[0], value[0]);
	}
	return (src);
}
