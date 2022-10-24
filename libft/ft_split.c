/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:03:08 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/20 18:42:34 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**string;
	int		num;
	int		i;
	int		start;

	num = 0;
	i = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			string[num] = (char *)malloc(sizeof(char) * (i - start + 1));
			ft_memmove(string[num], &s[i], i - start + 1);
			num++;
			start = i;
		}
		i++;
	}
	return (string);
}


bruno levi santos