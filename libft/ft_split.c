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

//separa a string original em varias diferentes cada vez que encontra c.
char	**stringcount(char const *s, char c)
{
	char	**string;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
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
	string = stringcount(s, c);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			string[num] = (char *)malloc(sizeof(char) * (i - start + 1));
			string[num][i - start] = 0;
			ft_memmove(string[num], &s[start], i - start);
			num++;
		}
	}
	return (string);
}
/* 
int	main(void)
{
	char	**string;
	int		i;

	i = 0;
	string = ft_split("lorem ipsum dolor", ' ');
	while (string[i])
	{
		printf("%s\n", string[i]);
		free (string[i]);
		i++;
	}
	free(string);
	return (0);
}
 */