/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:15:58 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/08 14:43:19 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printarg(va_list args, char c)
{
	{
		if (c == '%')
			write(1, &c, 1);
		else if (c == 'c')
			ft_putchar_fd(va_arg(args, int), 1);
		else if (c == 's')
			ft_putstr_fd(va_arg(args, char *), 1);
		else if (c == 'i' || 'u' || 'd')
			ft_putnbr_fd(va_arg(args, long int), 1);
		else if (c == 'x' || c == 'X' || c == 'p')
			ft_puthex_fd(va_arg(args, unsigned long int), 1, c);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else
		{
			i++;
			printarg(args, str[i]);
		}
		i++;
	}
	va_end(args);
	return (1);
}	

int	main(void)
{
	ft_printf("lets print a char %c, a string %s, a negative int %i, decimal %d and a long %u, a pointer %p\n", 'b', "bruno", -3, 9, -2147483647, (char *)1);
}
