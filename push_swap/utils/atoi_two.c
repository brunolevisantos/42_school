/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:37:01 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/20 09:55:50 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int atoi_two(char *string)
{
    int i;
    int sign;
    int y;
    
    i = 0;
    sign = 1;
    y = 0;
    if (*string == 0)
        return (0);
    while (string[i])
    {
        if (string[i] == '-')
        {
            sign *= -1;
            i++;
        }
        else if (string[i] <= '0' || string[i] >= '9')
        {
            write(2, "Error\n", 6);
            exit (0);
        }
        else
            y = y * 10 + string[i++] - '0';
    }
    if (y < INT_MIN || y > INT_MAX)
    {
        write(2, "Error\n", 6);
        exit (0);    
    }
    return (y * sign);
}