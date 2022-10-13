/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:02:33 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/13 12:14:13 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_memcpy(void *dest, const void *src, size_t n)
{
    char    *tmpdest;
    char    *tmpsrc;
    int     i;
    
    tmpdest = (char *)dest;
    tmpsrc = (char *)src;
    i = 0;
    while (i < n)
    {
        tmpdest[i] = tmpsrc[i];
        i++;
    }
}
