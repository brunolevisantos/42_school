/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:02:57 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/24 14:30:14 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	char	*start;

	sdup = (char *)malloc((sizeof(char *)) * (ft_strlen(s) + 1));
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