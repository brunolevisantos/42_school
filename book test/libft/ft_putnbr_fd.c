/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:31:01 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/09 11:11:33 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ALTERADO - RECEBE LN e RETORNA INT - 
escreve o n no ficheiro para onde aponta fd
 */
void	ft_putnbr_fd(long int n, int fd, int *bytesp)
{
	char	c;

	if (n == 0)
		*bytesp += write(fd, "0", 1);
	else if (n < 0)
	{
		n *= -1;
		*bytesp += write(fd, "-", 1);
		ft_putnbr_fd(n, fd, bytesp);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd, bytesp);
		ft_putnbr_fd(n % 10, fd, bytesp);
	}
	else if (n <= 9)
	{
		c = n + '0';
		*bytesp += write(fd, &c, 1);
	}
}
