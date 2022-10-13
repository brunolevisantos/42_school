/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:40:41 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/13 12:00:21 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}

/*
int main(void)
{
    char str[] = "hello world";
    int i;

    i = ft_strlen(str);
    ft_bzero(str, 6);
    write(1, str, i);
}
*/