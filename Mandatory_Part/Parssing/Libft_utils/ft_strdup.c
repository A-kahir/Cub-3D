/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:06:24 by akahir            #+#    #+#             */
/*   Updated: 2025/10/29 07:55:25 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

char	*ft_strdup(char *s1, int flag)
{
	char	*ptr;
	int		len;
	int		i;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	ptr = malloc_cl((len + 1) * sizeof(char), flag);
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
