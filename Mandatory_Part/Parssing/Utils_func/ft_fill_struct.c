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

#include "../../cub_mand.h"

static t_source	*ft_handle_rgb(t_source *src, char **var)
{
	char	*rgb_str;
	int		i;

	rgb_str = NULL;
	i = 1;
	while (var[i])
	{
		if (!rgb_str)
			rgb_str = ft_strdup(var[i]);
		else
			rgb_str = ft_strjoin(rgb_str, var[i]);
		i++;
	}
	src = ft_add_back(src, var[0], rgb_str);
	return (src);
}

static char	*ft_fill_key(char *line, char ch)
{
	char	*key;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != ch)
		i++;
	key = malloc_cl(i + 1, 0);
	if (!key)
		return (NULL);
	j = 0;
	while (j < i)
	{
		key[j] = line[j];
		j++;
	}
	key[j] = '\0';
	return (key);
}

static char	*ft_fill_value(char *line, int i, char ch)
{
	char	*value;
	int		j;

	while (line[i] && line[i] == ch)
		i++;
	if (!line[i])
		return (NULL);
	value = malloc_cl(ft_strlen(&line[i]) + 1, 0);
	if (!value)
		return (NULL);
	j = 0;
	while (line[i])
		value[j++] = line[i++];
	value[j] = '\0';
	return (value);
}

static char	**ft_split_vars(char *line, char ch)
{
	char	**res;
	int		i;

	if (!line)
		return (NULL);
	res = malloc_cl(sizeof(char *) * 3, 0);
	if (!res)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != ch)
		i++;
	res[0] = ft_fill_key(line, ch);
	if (!res[0])
		return (NULL);
	res[1] = ft_fill_value(line, i, ch);
	res[2] = NULL;
	return (res);
}

t_source	*ft_fill_struct(t_source *src, char *line)
{
	char	**var;
	char	*value;
	int		len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (line[len - 2] == '\r')
		line[len - 2] = '\0';
	var = ft_split_vars(line, ' ');
	if (!var)
		return (perror("variables"), NULL);
	value = var[1];
	if (!value || !value[0])
		return (NULL);
	if (var && (!ft_strncmp(var[0], "NO", 2) || !ft_strncmp(var[0], "SO", 2)
			|| !ft_strncmp(var[0], "WE", 2) || !ft_strncmp(var[0], "EA", 2)))
		src = ft_add_back(src, var[0], value);
	else if (!ft_strcmp(var[0], "F") || !ft_strcmp(var[0], "C"))
		src = ft_handle_rgb(src, var);
	else
		return (NULL);
	return (src);
}
