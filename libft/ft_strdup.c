/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:02:57 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/31 14:21:18 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	char	*start;

	sdup = (char *)malloc((sizeof(char)) * (ft_strlen(s) + 1));
	start = sdup;
	if (sdup == 0)
		return (0);
	while (*s)
	{
		*sdup = *s;
		s++;
		sdup++;
	}
	*sdup = 0;
	return ((char *)start);
}

// int	main (void)
// {
// 	printf("%s\n", ft_strdup("hello"));
// }