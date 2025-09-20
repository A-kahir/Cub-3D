#include "../cub_mand.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char		*dest;
	const char	*source;
	size_t		i;

	if (!dst && !src)
	{
		return (NULL);
	}
	if (dst == src)
	{
		return (dst);
	}
	dest = (char *)dst;
	source = (const char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
