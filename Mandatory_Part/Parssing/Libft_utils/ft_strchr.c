/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:10:06 by akahir            #+#    #+#             */
/*   Updated: 2025/08/15 18:10:21 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == (char)c)
		{
			return ((char *)(&s[i]));
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(&s[i]));
	}
	return (NULL);
}
