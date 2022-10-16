/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:04:27 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/16 19:35:03 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n && *s1 == *s2)
    {         
        s1++;
        s2++;
        i++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

// int main(void)
// {
//     printf("%d\n", ft_strncmp("bruno", "brupo", 5));
//     return (0);
// }
