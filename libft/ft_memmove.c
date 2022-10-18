/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:18:05 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/18 15:18:55 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//move o que esta no bloco src para o bloco dest.
//foi necesseario criar tmpdst que aponta para o mesmo sitio onde aponta dst original, por este ser void.
void    *ft_memmove(void *dest, const void *src, size_t n)
{
    char    *tmpdest;
    char    *tmpsrc;
    char    tmpmove;
    size_t  i;

    tmpdest = (char *)dest;
    tmpsrc = (char *)src;
    i = 0;
    while (i < n)
    {
        tmpmove = tmpsrc[i];
        tmpdest[i] = tmpmove;
        i++;
    }
    return (dest);
}
