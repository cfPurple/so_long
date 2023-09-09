/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:00:21 by cfelix            #+#    #+#             */
/*   Updated: 2023/04/20 22:00:27 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(va_list *args, char format)
{
	int		len;
	char	*str;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(*args, int));
	else if (format == 's')
	{
		str = va_arg(*args, char *);
		if (str == NULL)
			len += ft_print_str("(null)");
		else
		len += ft_print_str(str);
	}
	else if (format == 'p')
		len += ft_print_ptr(va_arg(*args, size_t));
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(*args, int));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;
	int		i;

	length = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += ft_formats(&args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}
