/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:25:16 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/18 15:18:09 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//compara 2 blocos de memoria ate ao size dado ou serem diferentes e retorna positivo/negativo na diferenca, ou 0 se forem iguais.
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;

    i = 0;
    if (n == 0)
        return (0);
    while (i < n && *(char *)s1 == *(char *)s2)
    {
        i++;
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
