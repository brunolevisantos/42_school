/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:51:59 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/19 12:02:05 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copia a string src para a string dst e retorna o tamanho da dest.
size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

    i = 0;
	if (size == 0)
		return (ft_strlen(src));
    while (i < size - 1 && src[i] != 0)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
    return (ft_strlen(src));
}
