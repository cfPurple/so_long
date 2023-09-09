#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	char *str;

	str = (char*)s;
	i = 0;
	while (*str && i < n)
	{
		if (*str == c)
			return (str); 
		str++;
		i++;
	}
	return (0);
}