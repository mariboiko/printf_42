/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboiko <mboiko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:42:35 by mboiko            #+#    #+#             */
/*   Updated: 2022/10/12 15:44:55 by mboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		i += write(1, "-", 1);
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	if (nb < 10)
	{
		i += ft_putchar (nb + '0');
	}
	return (i);
}
