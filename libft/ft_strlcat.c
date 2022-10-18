/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:24:30 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/18 15:21:34 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//concatena duas strings ate ao size e retorna o tamanho total.
size_t  ft_strlcat(char *dst, char *src, size_t size)
{
    size_t i;
    size_t j;
    size_t n;
    size_t m;

    i = 0;
    j = ft_strlen(dst);
    n = ft_strlen(dst);
    m = ft_strlen(src);
    if (size <= j)
        return (size + m);
    while (j < size - 1 && src[i])
    {
        dst[j] = src[i];
        i++;
        j++;
    }
    dst[j] = 0;
    return (n + m);
}


// int main(void)
// {
//     char    src[] = " world";
//     char    dst[] = "hello";

//     printf("%zu\n", ft_strlcat(dst, src, 8));
//     printf("%s\n", dst);
//     return (0);
// }
