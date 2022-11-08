/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:52:35 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/08 16:30:15 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthex_fd(unsigned long int n, int fd, char c)
{
	char	*base;

	if (c == 'p')
		write(1, "0x", 2);
	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < ft_strlen(base))
		ft_putchar_fd(base[n], fd);
	else
	{
		ft_puthex_fd(n / ft_strlen(base), 1, c);
		ft_puthex_fd(n % ft_strlen(base), 1, c);
	}
}
