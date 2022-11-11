/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:49:12 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/01 18:43:43 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Aloca uma memoria de n elementos de tamanho "element size" e preenche com 0.
void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	ptr = malloc(nelem * elsize);
	if (!ptr)
		return (0);
	else
		ft_bzero(ptr, (nelem * elsize));
	return (ptr);
}
