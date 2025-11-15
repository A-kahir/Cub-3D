/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:30:04 by akahir            #+#    #+#             */
/*   Updated: 2025/11/14 02:24:43 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

int	ft_parsing(int argc, char **argv)
{
	if (argc != 2)
		return (print_message(0, NULL, '\0'), -1);
	if (argv[1])
		if (ft_strstr(argv[1], ".cub") == NULL)
			return (print_message(1, NULL, '\0'), -1);
	return (0);
}

void	ft_norm_check_hexa(t_source *curr)
{
	int	i;

	i = 0;
	while (curr->value[i++])
		if ((curr->value[i] == ',' && curr->value[i + 1] == ',')
			|| curr->value[0] == ',')
			return (print_message(11, NULL, '\0'), malloc_cl(0, 2),
				(void) NULL);
}
