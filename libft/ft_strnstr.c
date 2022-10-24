/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:23:19 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/24 14:32:16 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//procura na string big a string little. caso encontre totalmente ate ao size, retorna ponteiro para onde comecou a ser igual.
char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t		i;
	const char	*tmp;
	const char	*start;

	i = 0;
	tmp = little;
	if (*little == 0)
		return ((char *)big);
	while (i < n && *big)
	{
		start = big;
		while (i < n && *little == *big && *little)
		{
			if (!*(little + 1))
				return ((char *)start);
			little++;
			big++;
			i++;
		}
		big++;
		little = tmp;
		i++;
	}
	return (0);
}
