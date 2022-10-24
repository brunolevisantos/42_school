/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:02:33 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/24 14:26:55 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copia para o bloco de memoria dest o que esta no bloco src, ate ao size.
//foi preciso type cast por serem void.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmpdest;
	char	*tmpsrc;
	size_t	i;

	tmpdest = (char *)dest;
	tmpsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		tmpdest[i] = tmpsrc[i];
		i++;
	}
	return (dest);
}
