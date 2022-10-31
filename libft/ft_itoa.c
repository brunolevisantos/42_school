/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:24:51 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/31 19:34:45 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//aloca uma (char) string e preenche com o int.
char	*alloc(size_t s)
{
	char	*str;

	str = (char *)malloc((sizeof(char) * (s + 1)));
	str[s] = 0;
	return (str);
}

size_t	count(long int ln)
{
	size_t		s;
	long int	count;
	int			sign;

	s = 0;
	count = ln;
	sign = 0;
	if (ln < 0)
	{
		sign = 1;
		count *= -1;
	}
	if (count == 0)
		s = 1;
	while (count > 0)
	{
		count = count / 10;
		s++;
	}
	return (s + sign);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	ln;

	ln = n;
	i = count(ln) - 1;
	str = alloc(count(ln));
	if (ln < 0)
	{
		str[0] = '-';
		ln *= -1;
	}
	if (ln == 0)
	{
		str[i] = '0';
		return (str);
	}
	while (ln > 0)
	{
		str[i] = ln % 10 + '0';
		ln = ln / 10;
		i--;
	}
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// }
