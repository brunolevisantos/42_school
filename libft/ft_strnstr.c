/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:23:19 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/31 08:01:09 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* procura na string big a string little. caso encontre totalmente ate ao size, 
retorna ponteiro para onde comecou a ser igual. */
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

// int	main(void)
// {
// 	printf("%s\n", ft_strnstr("aaabcabcd", "aabc", 1));
// }
