#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    char *tab;

    if (count == 0 || size == 0)
        return (malloc (0));
    if (!(tab = malloc(count * size)))
        return (NULL);
    ft_bzero(tab, count * size);
    return (tab);
}