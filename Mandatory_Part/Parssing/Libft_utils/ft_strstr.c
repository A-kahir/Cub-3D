/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:40:44 by akahir            #+#    #+#             */
/*   Updated: 2025/09/12 13:41:11 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char    *ft_strstr(char *haystack, char *needle)
{
    size_t i;
    size_t j;

    if (!*needle)
        return ((char *)haystack);
    i = 0;
    while (haystack[i])
    {
        j = 0;
        while (haystack[i + j] && haystack[i + j] == needle[j])
        {
            j++;
            if (!needle[j])
                return ((char *)(haystack + i));
        }
        i++;
    }
    return (NULL);
}
