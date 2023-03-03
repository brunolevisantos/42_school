/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:00:06 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/24 13:09:11 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//tamanho da string.
size_t	ft_strlen_print(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
