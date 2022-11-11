/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:43:19 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/09 11:08:23 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ALTERADO - RECEBE PTR BYTS - 
escreve o caracter c no ficheiro para onde aponta o fd 
 */
void	ft_putchar_fd(char c, int fd, int *bytesp)
{
	write(fd, &c, 1);
	*bytesp++;
}
