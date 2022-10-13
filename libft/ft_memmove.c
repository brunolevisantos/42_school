/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:18:05 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/13 12:26:48 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    char    *tmpdest;
    char    *tmpsrc;
    char    tmpmove;
    int     i;

    tmpdest = (char *)dest;
    tmpsrc = (char *)src;
    i = 0;
    while (i < n)
    {
        tmpmove = tmpsrc[i];
        tmpdest[i] = tmpmove;
        i++;
    }
}
