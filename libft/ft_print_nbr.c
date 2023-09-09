/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:09:46 by cfelix            #+#    #+#             */
/*   Updated: 2023/04/20 22:09:48 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_nbr(int n)
{
	long long	div;
	long long	ni;

	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	ni = n;
	if (ni < 0)
	{
		ni = -ni;
		ft_putchar('-');
	}
	div = 1;
	while (div <= ni)
		div = div * 10;
	while (div >= 10)
	{
		div = div / 10;
		ft_putchar((ni / div) + '0');
		ni = ni % div;
	}
}

int	ft_print_nbr(int num)
{
	int			len;
	long long	n;

	len = 0;
	n = num;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	ft_put_nbr(num);
	if (num == 0)
		return (1);
	return (len);
}
