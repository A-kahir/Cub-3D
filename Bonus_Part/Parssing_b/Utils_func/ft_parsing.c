/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:30:04 by akahir            #+#    #+#             */
/*   Updated: 2025/09/27 08:58:55 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

int	ft_parsing(int argc, char **argv)
{
	if (argc != 2)
		return (print_message(0, NULL, '\0'), -1);
	if (argv[1])
		if (ft_strstr(argv[1], ".cub") == NULL)
			return (print_message(1, NULL, '\0'), -1);
	return (0);
}
