/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:18:05 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/31 20:03:13 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//move o que esta no bloco src para o bloco dest.
//foi necesseario criar tmpdst que aponta para o mesmo 
//sitio onde aponta dst original, por este ser void.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmpdest;
	char	*tmpsrc;
	size_t	i;

	tmpdest = (char *)dest;
	tmpsrc = (char *)src;
	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			tmpdest[i - 1] = tmpsrc[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			tmpdest[i] = tmpsrc[i];
			i++;
		}
	}
	return (dest);
}

/* int	main(void)
{
	char	src[] = "hello";
	char	dest[] = "blabla";

	printf("%s\n", (char *)ft_memmove(dest, src, 4));
	return (0);
}
 */