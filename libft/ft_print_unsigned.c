/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:16:25 by cfelix            #+#    #+#             */
/*   Updated: 2023/04/20 22:18:56 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_unsigned(unsigned int n)
{
	long long	div;

	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	div = 1;
	while (div <= n)
		div = div * 10;
	while (div >= 10)
	{
		div = div / 10;
		ft_putchar((n / div) + '0');
		n = n % div;
	}
}

int	ft_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	ft_put_unsigned(n);
	if (n == 0)
		return (1);
	return (ft_unsigned_len(n));
}
