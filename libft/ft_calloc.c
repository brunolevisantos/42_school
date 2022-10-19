/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:49:12 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/20 00:06:58 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Aloca uma memoria de n elementos de tamanho "element size" e preenche com 0.
void    *ft_calloc(size_t nelem, size_t elsize)
{
    void    *ptr;
    
    ptr = malloc(nelem * elsize);
    if (ptr == 0)
        return (0);
    else
        ft_bzero(ptr, nelem);
    return (ptr);
}
