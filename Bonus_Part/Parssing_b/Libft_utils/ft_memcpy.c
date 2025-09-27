/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 02:26:48 by ifaleh            #+#    #+#             */
/*   Updated: 2025/09/21 02:26:48 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char		*dest;
	const char	*source;
	size_t		i;

	if (!dst && !src)
	{
		return (NULL);
	}
	if (dst == src)
	{
		return (dst);
	}
	dest = (char *)dst;
	source = (const char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
