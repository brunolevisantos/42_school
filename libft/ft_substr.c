/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:17:06 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/20 10:34:33 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copia parte da string original para uma nova, entre o start e o len
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*substart;
	size_t	sfinish;

	sfinish = start + len;
	sub = (char *)malloc(sizeof(char *) * len + 1);
	substart = sub;
	if (sub == 0)
		return (0);
	if (start > ft_strlen(s))
		return ("");
	else
	{
		while (start < sfinish)
		{
			*sub = s[start];
			sub++;
			start++;
		}
	}
	*sub = 0;
	return (substart);
}

// int	main(void)
// {
// 	printf("%s\n", ft_substr("bruno levi santos", 200, 3));
// }