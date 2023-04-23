/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:49:12 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/11 19:01:30 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Aloca uma memoria de n elementos de tamanho "element size" e preenche com 0.
// void	*ft_calloc(size_t nelem, size_t elsize)
// {
// 	void	*ptr;

// 	ptr = malloc(nelem * elsize);
// 	if (!ptr)
// 		return (0);
// 	else
// 		ft_bzero(ptr, (nelem * elsize));
// 	return (ptr);
// }

void	*ft_calloc(size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	i = -1;
	if (size != 0)
		while (++i < size)
			((char *)ptr)[i] = 0;
	return (ptr);
}
