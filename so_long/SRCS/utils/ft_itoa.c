/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:24:51 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/24 14:54:52 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

//recebe um int e aloca uma str preenchendo a com o n (transforma em char)
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
	str = (char *)ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	if (ln < 0)
	{
		str[0] = '-';
		ln *= -1;
	}
	if (ln == 0)
		str[i] = '0';
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
