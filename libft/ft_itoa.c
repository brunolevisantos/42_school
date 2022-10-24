/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:24:51 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/24 23:56:07 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*allocate(size_t s)
{
	char	*str;

	str = (char *)malloc((sizeof(char) * s + 1));
	return (str);
}

size_t	count(int n)
{
	size_t	s;
	int		count;
	
	s = 0;
	count = n;
	while (count / 10 > 0)
	{
		count = count / 10;
		s++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	int	i;
	
	i = 0;
	str = allocate(count(n));
	if (n <= 9)
	{
		str[i] = n - '0';
	}
	return (str);
}

int	main(void)
{
	printf("%s\n", ft_itoa(30));
}