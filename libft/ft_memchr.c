/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:04:02 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/18 09:46:57 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    int i;

    i = 0;
    while (*(char *)s && i <= n)
    {
        if (*(char *)s == c)
            return (s);
        i++;
        s++;
    }
    return (0);
}
