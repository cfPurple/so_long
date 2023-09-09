#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char *temp1;
	char *temp2;

	temp1 = (char *)src;
	temp2 = (char *)dest;
	i = 0;
	if (temp2 > temp1)
	{
		while (n-- > 0)
			temp2[n] = temp1[n];
	}
	else
	{
		while (i < n)
		{
			temp2[i] = temp1[i];
			i++;
		}
	}
	return (dest);

}