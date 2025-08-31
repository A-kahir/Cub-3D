/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:46:28 by akahir            #+#    #+#             */
/*   Updated: 2025/08/31 18:30:46 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void ft_debug(t_source *src, int flag)
{
    t_source *tmp = src;

    if (flag == 1)
    {
        while (tmp)
        {
            printf("tmp ===> %s = %s\n", tmp->var, tmp->value);
            if (tmp->colors)
            {
                if (tmp->colors->hexa_rgb_f)
                    printf("tmp->colors->hexa_rgb_f ==> %d\n", tmp->colors->hexa_rgb_f);
                if (tmp->colors->hexa_rgb_c)
                    printf("tmp->colors->hexa_rgb_c ==> %d\n", tmp->colors->hexa_rgb_c);
            }
            tmp = tmp->next;
        }
        printf("\n*************************************=> MAP <=*************************************\n\n");
        int i = 0;
        if (src->map)
        {
            while (src->map[i])
            {
                printf("%s\n", src->map[i]);
                i++;
            }
        }
    }
}
