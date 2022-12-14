/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:43:19 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/26 10:45:50 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* escreve o caracter c no ficheiro para onde aponta o fd 
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
