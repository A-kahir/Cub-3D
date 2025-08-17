#include "../../parsing.h"

t_source *ft_fill_struct(t_source *src, char *line)
{
	char **var;
	char **value;

	if (!line)
		return (NULL);
	var = ft_split(line, ' ');
	if (!var)
		return (perror("split"), NULL);
	value = ft_split(var[1], '\n');
	if (!value || !value[0])
		return (src);
	if (var && (!ft_strncmp(var[0], "NO", 2) || !ft_strncmp(var[0], "SO", 2)
		|| !ft_strncmp(var[0], "WE", 2) || !ft_strncmp(var[0], "WE", 2)
		|| !ft_strncmp(var[0], "EA", 2) || !ft_strcmp(var[0], "F")
		|| !ft_strcmp(var[0], "C")))
		{
			src = ft_add_back(src, var[0], value[0]);
		}
	return (src);
}
