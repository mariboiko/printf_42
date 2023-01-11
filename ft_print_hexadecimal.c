/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboiko <mboiko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:09:45 by mboiko            #+#    #+#             */
/*   Updated: 2022/10/12 16:44:15 by mboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexadecimal(unsigned long int nb, char c)
{
	int	i;

	i = 0;
	if (c == 'x' || c == 'p')
	{
		if (nb >= 16)
			i = ft_print_hexadecimal(nb / 16, c);
		i += ft_putchar("0123456789abcdef"[nb % 16]);
	}
	if (c == 'X')
	{
		if (nb >= 16)
			i = ft_print_hexadecimal(nb / 16, c);
		i += ft_putchar("0123456789ABCDEF"[nb % 16]);
	}
	return (i);
}
