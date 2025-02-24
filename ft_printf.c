/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihakoby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:13:35 by sihakoby          #+#    #+#             */
/*   Updated: 2025/02/24 11:04:27 by sihakoby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthextoptr(void *ptr)
{
	int				count;
	unsigned long	memaddress;

	memaddress = (unsigned long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex(memaddress, 0);
	return (count);
}

int	ft_print_cases(char c, va_list args)
{
	size_t	count;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (c == 'p')
		count += ft_puthextoptr(va_arg(args, void *));
	else if (c == 'u')
		count += ft_putunit(va_arg(args, unsigned int));
	return (count);
}

int	ft_printf(const char *printed_txt, ...)
{
	va_list	args;
	size_t	count;

	va_start(args, printed_txt);
	count = 0;
	while (*printed_txt)
	{
		if (*printed_txt == '%')
		{
			printed_txt++;
			count += ft_print_cases(*printed_txt, args);
		}
		else
			count += write(1, printed_txt, 1);
		printed_txt++;
	}
	va_end(args);
	return (count);
}
