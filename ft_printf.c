/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboiko <mboiko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:26:01 by mboiko            #+#    #+#             */
/*   Updated: 2022/11/15 15:12:53 by mboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_work_types(va_list args, char x)
{
	int	i;

	i = 0;
	if (x == 'c')
		i += ft_putchar(va_arg(args, int));
	if (x == '%')
		i += ft_putchar('%');
	if (x == 's')
		i += ft_putstr(va_arg(args, char *));
	if (x == 'd')
		i += ft_putnbr(va_arg(args, int));
	if (x == 'i')
		i += ft_putnbr(va_arg(args, int));
	if (x == 'u')
		i += ft_print_u(va_arg(args, unsigned int));
	if (x == 'x')
		i += ft_print_hexadecimal(va_arg(args, unsigned int), x);
	if (x == 'X')
		i += ft_print_hexadecimal(va_arg(args, unsigned int), x);
	if (x == 'p')
		i += ft_putstr("0x")
			+ ft_print_hexadecimal(va_arg(args, unsigned long int), x);
	return (i);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
			count += ft_work_types(args, *++str);
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
