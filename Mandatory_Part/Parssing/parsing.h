/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:08:37 by akahir            #+#    #+#             */
/*   Updated: 2025/08/15 16:08:37 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>


typedef enum s_mal
{
	ALLOCATION,
	FREE,
}	t_mal;

typedef struct s_leaks
{
	char			*ptr;
	struct s_leaks	*next;
}	t_leaks;

typedef struct s_texture
{
	int	north_txt;
	int	south_txt;
	int	east_txt;
	int	west_txt;
}	t_texture;


//principale func:


//Utils func:
void	print_message(int flag);

//Libft utils:
void	*malloc_cl(size_t size, t_mal mode);
int		ft_strcmp(char *s1, char *s2);

#endif