/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:12:09 by cfelix            #+#    #+#             */
/*   Updated: 2023/04/20 22:12:11 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr_len(size_t num)
{
	size_t	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(size_t nb, char *str)
{
	size_t	c;

	if (nb == 0)
		return ;
	c = nb % 16;
	ft_put_ptr(nb / 16, str);
	ft_putchar(str[c]);
}

int	ft_print_ptr(size_t ptr)
{
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		ft_put_ptr(ptr, "0123456789abcdef");
	}
	return (ft_ptr_len(ptr) + 2);
}