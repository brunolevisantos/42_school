/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:15:58 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/11 10:38:01 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printarg(va_list args, char c, int *bytesp)
{
	{
		if (c == '%')
			(*bytesp) += write(1, &c, 1);
		else if (c == 'c')
			ft_putchar_fd(va_arg(args, int), 1, bytesp);
		else if (c == 's')
			ft_putstr_fd(va_arg(args, char *), 1, bytesp);
		else if (c == 'i' || c == 'd')
			ft_putnbr_fd(va_arg(args, int), 1, bytesp);
		else if (c == 'u')
			ft_putnbr_fd(va_arg(args, unsigned int), 1, bytesp);
		else if (c == 'p')
			ft_puthex_fd(va_arg(args, unsigned long int), 1, c, bytesp);
		else if (c == 'x' || c == 'X')
			ft_puthex_fd(va_arg(args, unsigned int), 1, c, bytesp);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		bytesp;
	va_list	args;

	i = 0;
	bytesp = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			bytesp += write(1, &str[i], 1);
		else
		{
			i++;
			printarg(args, str[i], &bytesp);
		}
		i++;
	}
	va_end(args);
	return (bytesp);
}
