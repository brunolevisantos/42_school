/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:31:01 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/26 09:44:14 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		c;

	ln = n;
	if (ln == 0)
		write(fd, "0", 1);
	if (ln < 0)
	{
		ln *= -1;
		write(fd, "-", 1);
	}
	while (ln > 0)
	{
		c = ln % 10 + '0';
		write(fd, &c, 1);
		ln /= 10;
	}
}
