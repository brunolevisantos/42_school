/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:04:02 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/31 23:46:10 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//retorna ponteiro para onde encontra c, caso encontre.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	c = (char)c;
	i = 0;
	while (s && i < n)
	{
		if (*(char *)s == c)
			return ((void *)s);
		i++;
		s++;
	}
	return (0);
}
