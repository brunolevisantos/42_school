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

char	**stringcount(char const *s, char c)
{
	char	**string;
	int		i;
	int		count;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i + 1] != c)
			i++;
		count++;
	}
	printf ("%d\n", count);
	string = (char **)malloc((sizeof (char *)) * (count + 1));
	string[count] = 0;
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	int		num;
	int		i;
	int		start;

	num = 0;
	i = 0;
	start = 0;
	string = stringcount(s, c);
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

int	main(void)
{
	char	**string;
	int		i;

	i = 0;
	string = ft_split("bruno levi santos", ' ');
	while (i < 3)
	{
		printf("%s\n", string[i]);
		i++;
	}
	return (0);
}
