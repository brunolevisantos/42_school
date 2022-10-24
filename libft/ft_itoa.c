/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:24:51 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/24 18:42:48 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	
	
	i = 0;
	while (n / 10 > 1)
	{
		n = n / 10;
		i++;
	}
	str = (char *)malloc((sizeof(char) * i + 1));
	if (n <= 9)
	{
		ft_itoa(n - 0);
	}
	return (str);
}

int	main(void)
{
	printf("%s\n", ft_itoa(3));
}