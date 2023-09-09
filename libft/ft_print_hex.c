/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:07:41 by cfelix            #+#    #+#             */
/*   Updated: 2023/04/20 22:07:44 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_conv_hex(unsigned int nb, char *str)
{
	int	c;

	if (nb == 0)
		return ;
	c = nb % 16;
	ft_conv_hex(nb / 16, str);
	ft_putchar(str[c]);
}

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_find_format(unsigned int num, char format)
{
	if (format == 'x')
		ft_conv_hex(num, "0123456789abcdef");
	if (format == 'X')
		ft_conv_hex(num, "0123456789ABCDEF");
}

int	ft_print_hex(unsigned int num, char format)
{
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_find_format(num, format);
	return (ft_hex_len(num));
}
