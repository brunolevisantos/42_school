/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:52:35 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/09 14:42:16 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_fd(unsigned long int n, int fd, char c, int *bytesp)
{
	char	*base;

	if (c == 'p')
	{
		if (!n)
			*bytesp += write(1, "(nil)", 5);
		else
		{
			*bytesp += write(1, "0x", 2);
			ft_putpointer_fd(n, 1, bytesp);
		}
		return ;
	}
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < ft_strlen(base))
		ft_putchar_fd(base[n], fd, bytesp);
	else
	{
		ft_puthex_fd(n / ft_strlen(base), 1, c, bytesp);
		ft_puthex_fd(n % ft_strlen(base), 1, c, bytesp);
	}
}
