/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:31:01 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/26 10:56:58 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* converte em long int e escreve o n no ficheiro para onde aponta fd
 */
void	therealputnbr(long int ln, int fd)
{
	char	c;

	if (ln == 0)
		write(fd, "0", 1);
	else if (ln < 0)
	{
		ln *= -1;
		write(fd, "-", 1);
		therealputnbr(ln, fd);
	}
	else if (ln > 9)
	{
		therealputnbr(ln / 10, fd);
		therealputnbr(ln % 10, fd);
	}
	else if (ln <= 9)
	{
		c = ln + '0';
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;

	ln = n;
	therealputnbr(ln, fd);
}
