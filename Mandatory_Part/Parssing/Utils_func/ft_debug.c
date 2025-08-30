/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:46:28 by akahir            #+#    #+#             */
/*   Updated: 2025/08/30 21:55:58 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

void ft_debug(t_source *src, int flag)
{
    t_source *tmp = src;

    if (flag == 1)
    {
        while (tmp)
        {
            printf("tmp ===> %s = %s\n", tmp->var, tmp->value);
            tmp = tmp->next;
        }
        tmp = src;
        while (tmp)
        {
            printf("*R ====> %d\n", tmp->colors->r);
            printf("*G ====> %d\n", tmp->colors->g);
            printf("*B ====> %d\n", tmp->colors->b);
            tmp = tmp->next;
        }
        printf("\n********************************************\n\n");
        int i = 0;
        while (src->map[i])
        {
            printf("%s\n", src->map[i]);
            i++;
        }
    }
}