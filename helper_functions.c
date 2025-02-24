/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihakoby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:05:16 by sihakoby          #+#    #+#             */
/*   Updated: 2025/02/24 11:12:21 by sihakoby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(int num)
{
	size_t	count;

	count = 0;
	if (num == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		num = 147483648;
	}
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
	}
	count += ft_putchar((num % 10) + '0');
	return (count);
}

unsigned int	ft_putunit(unsigned int u_int)
{
	size_t	count;

	count = 0;
	if (u_int > 9)
	{
		count += ft_putnbr(u_int / 10);
	}
	count += ft_putchar((u_int % 10) + '0');
	return (count);
}

int	ft_puthex(unsigned long num, int upperorlowercase)
{
	char	*base;
	int		count;

	count = 0;
	if (upperorlowercase == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num >= 16)
		count += ft_puthex(num / 16, upperorlowercase);
	count += ft_putchar(base[num % 16]);
	return (count);
}
