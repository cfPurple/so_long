/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:46:53 by cfelix            #+#    #+#             */
/*   Updated: 2022/12/06 17:48:35 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{	
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	w_count(char *s, char c)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (s[i])
	{
		while (c == s[i] && s[i])
			i++;
		if (c != s[i] && s[i])
		{
			nbr++;
			while (c != s[i] && s[i])
				i++;
		}
	}
	return (nbr);
}

int	c_count(char *s, char c)
{
	int	i;

	i = 0;
	while (c != s[i] && s[i])
	{
		i++;
	}
	return (i);
}

char	**writetab(char **tab, char *str, char c)
{
	int		n;
	int		i;

	n = 0;
	while (*str)
	{
		while (c == *str && *str)
			str++;
		if (*str == '\0')
			break ;
		if (c != *str && *str)
		{
			tab[n] = malloc(sizeof(char) * (c_count(str, c) + 1));
			if (!tab[n])
				return (freetab(tab), NULL);
		}
		i = 0;
		while (c != *str && *str)
			tab[n][i++] = *str++;
		tab[n++][i] = '\0';
	}
	tab[n] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	tab = malloc(sizeof(char *) * (w_count(str, c) + 1));
	if (!tab)
		return (NULL);
	tab = writetab(tab, str, c);
	return (tab);
}
