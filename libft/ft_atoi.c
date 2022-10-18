/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:27:32 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/18 10:54:45 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//retorna o primeiro conjunto de numeros encontrados na string como int.
int ft_atoi(const char *nptr)
{
    int y;
    int sign;
    
    y = 0;
    sign = 1;
    while (*nptr <= 32)
        nptr++;
    if (*nptr == 43 || *nptr == 45)
    {
        if (*nptr == 45)
            sign *= -1;
        nptr++;
    }
    while (*nptr >= 48 && *nptr <= 57)
    {
        y = *nptr * 10 + *nptr - '0';
        nptr++;
    }
    return (y * sign);        
}
