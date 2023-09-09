#include<stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		strlen;

	i = 0;
	strlen = 0;
	while (src[strlen])
		strlen++;
	dest = malloc(sizeof(char) * strlen + 1);
	if (! dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}