/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:28:53 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/24 14:32:39 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Encontra e retorna um ponteiro para a ultima ocorrencia da char c.
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (*s)
		s++;
	if (c == 0)
		return ((char *)s);
	while (i >= 0)
	{
		if (*s == c)
			return ((char *)s);
		i--;
		s--;
	}
	return (0);
}

// int main(void)
// {
//     char s[] = "hipopotamo";

//     printf("%s\n", ft_strrchr(s, 0));
//     return (0);
// }