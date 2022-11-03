/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:17:06 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/03 15:36:23 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copia parte da string original para uma nova, entre o start e o len
char	*allocat(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (len >= ft_strlen(s))
		sub = (char *)ft_calloc((ft_strlen(s) - start + 1), sizeof(char));
	else
		sub = (char *)ft_calloc((len + 1), sizeof(char));
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*substart;
	size_t	sfinish;

	if (!s || start > ft_strlen(s))
		return ((char *)ft_calloc(1, (sizeof(char))));
	sub = allocat(s, start, len);
	if (sub == 0)
		return (0);
	else
	{
		if (len > ft_strlen(s))
			sfinish = ft_strlen(s);
		else
			sfinish = start + len;
		substart = sub;
		while (start < sfinish)
		{
			*sub = s[start];
			sub++;
			start++;
		}
	}
	return (substart);
}

// int	main(void)
// {
// 	printf("%s\n", ft_substr("bruno levi santos", 200, 3));
// }