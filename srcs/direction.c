/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:06:40 by cfelix            #+#    #+#             */
/*   Updated: 2023/09/09 15:07:33 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gps(t_map *data, int *x, int *y, char c)
{
	int	i;
	int	p;

	i = 0;
	while (data->map[i] != NULL)
	{
		p = ft_index(data->map[i], c);
		if (p != -1)
		{
			*y = i;
			*x = p;
		}
		i++;
	}
}

void ft_clear(void **data)
{
    int i

    i = 0;
	if (data == NULL)
		return ;
    while (data[i])
    {
        free(data[i]);
        i++;
    }
    free(data);
    *data = NULL;
}

int	ft_index(const char *str, char c)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return index;
		index++;
	}
	return (-1);
}