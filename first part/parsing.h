


#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <stdio.h>
# include "../minilibx_opengl_20191021/mlx.h" //not sure from fractol


typdef enum s_mal
{
	ALLOCATE;
	FREE_ALL;
}	t_mal;

typedef struct s_leaks
{
	char *ptr;
	struct s_leaks *next;
}   t_leaks;

typedef struct s_texture
{
	int	north_txt;
	int	south_txt;
	int	east_txt;
	int	west_txt;
}	t_texture;


//principale func:


//Libft utils:
void *malloc_cl(size_t size, t_mal *mode);


# endif