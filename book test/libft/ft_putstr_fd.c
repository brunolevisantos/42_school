/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:14:22 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/09 11:06:05 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ALTERADO - RECEBE PTR BYTS - escreve a str no ficheiro para onde aponta o fd 
 */
void	ft_putstr_fd(char *s, int fd, int *bytesp)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
		*bytesp++;
	}
}
