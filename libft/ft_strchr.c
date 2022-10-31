/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:04:38 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/30 20:48:47 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//procura na string um elemento c, e retorna
//o ponteiro para onde foi encontrado.
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
	s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

/*
int main(void)
{
    char s[] = "duarte";
    
    printf("%s", ft_strchr(s, 0));
    return(0);
}
*/
