/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:15:58 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/09 15:27:16 by bde-seic         ###   ########.fr       */
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
/* 
int	main(void)
{
	int	i;

	i = 10;
//	printf("%d\n", ft_printf("percent sign %%\n"));
//	printf("%d\n", ft_printf("char %c\n", 'b'));
//	printf("%d\n", ft_printf("string %s\n", "bruno"));
//	printf("%d\n", ft_printf("pointer %p\n", (char *)140));
//	printf("%d\n", ft_printf("unsigned %u\n", -1));
//	printf("%d\n", ft_printf("lets print a percent sign %%, 
//	char %c, a string %s, a negative int %i, decimal %d and a 
//	unsigned %u, a pointer %p\n", 'b', "bruno", -2, 9, -1, &i));
//	printf("%d\n", ft_printf(" NULL %s NULL ", NULL));
//	printf("%d\n", printf(" NULL %s NULL ", NULL));
}
 */