/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:02:57 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/18 15:30:02 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s)
{
    const char    *sdup;
    const char    *start;
    
    sdup = (char *)malloc((sizeof(char *)) * ft_strlen(s) + 1);
    start = sdup;
    if (sdup == 0)
        return (0);
    while (*s)
    {
        sdup = s;
        s++;
        sdup++;
    }
    sdup++;
    sdup = 0;
    return ((char *)start);
}
