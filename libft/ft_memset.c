/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:07:31 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/13 11:56:31 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    size_t  i;
    char   *ptr;

    i = 0;
    ptr = (char *)s;
    while (i < n)
    {
        ptr[i] = c;
        i++;
    }
    return (s);
}

/*
Na linha 21 foi preciso conerter o void pointer para char pointer,
caso contrario nao daria dar valor, por ser void (nao tem tipo - string/array)

int main(void)
{
    char str[] = "hello world";

    ft_memset((void *)str, 'b', 5);
    printf("%s\n", str);
    return (0);
}
*/
