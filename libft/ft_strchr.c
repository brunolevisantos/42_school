/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:04:38 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/02 10:31:43 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//procura na string um elemento c, e retorna
//o ponteiro para onde foi encontrado.
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
	s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

// int main(void)
// {
//     char s[] = "teste";
//     printf("%s", ft_strchr("", 97));
//     return(0);
// }
