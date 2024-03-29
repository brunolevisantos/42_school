/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:49:12 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/24 15:41:04 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
