/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:43:19 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/26 09:27:56 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

/* escreve o caracter c no ficheiro para onde aponta o fd 
 */
void	ft_puthcar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
