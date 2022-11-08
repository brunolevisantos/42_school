/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:23:19 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/01 17:15:32 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* procura na string big a string little. caso encontre totalmente ate ao size, 
retorna ponteiro para onde comecou a ser igual. */
char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t		b;
	size_t		l;

	b = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (b < n && big[b])
	{
		l = 0;
		while (little[l] == big[b + l] && (b + l) < n)
		{
			if (!(little[l + 1]))
				return ((char *)&big[b]);
			l++;
		}
		b++;
	}
	return (0);
}

/* int	main(void)
{
	printf("%s\n", ft_strnstr("aaabcabcd", "abcd", 9));
}
 */