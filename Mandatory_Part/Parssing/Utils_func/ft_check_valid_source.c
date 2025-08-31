#include "../parsing.h"

int ft_chack_valid_source(char *str)
{
	if (!str)
		return (-1);
	if ((str[0] == 32 || (str[0] >= 9 && str[0] <= 13)))
		return (-1);
	if (str[0] == '\n' || str[0] == '\0')
		return (-1);
	return (0);
}
