/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:16:56 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/24 13:11:16 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointer_fd(unsigned long int n, int fd, int *bytesp)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < ft_strlen_print(base))
		ft_putchar_fd(base[n], fd, bytesp);
	else
	{
		ft_putpointer_fd(n / ft_strlen_print(base), 1, bytesp);
		ft_putpointer_fd(n % ft_strlen_print(base), 1, bytesp);
	}
}
