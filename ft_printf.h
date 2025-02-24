/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihakoby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:08:17 by sihakoby          #+#    #+#             */
/*   Updated: 2025/02/24 11:14:51 by sihakoby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>

int				ft_putchar(int c);
int				ft_putstr(const char *str);
int				ft_putnbr(int num);
unsigned int	ft_putunit(unsigned int u_int);
int				ft_puthex(unsigned long num, int upperorlowercase);
int				ft_puthextoptr(void *ptr);
int				ft_print_cases(char c, va_list args);
int				ft_printf(const char *printed_txt, ...);
#endif
