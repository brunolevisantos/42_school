/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:09:13 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/24 14:33:03 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	notcharset1(const char *s1, const char *set)
{
	int	start;
	int	i;

	start = 0;
	while (s1[start])
	{
		i = 0;
		while (set[i])
		{
			if (s1[start] == set[i])
			{
				start++;
				break ;
			}
			else if (set[i + 1] == 0)
				return (start);
			i++;
		}
	}
	return (start);
}

int	notcharset2(const char *s1, const char *set)
{
	int	end;
	int	i;

	end = ft_strlen(s1) - 1;
	while (end != 0)
	{
		i = 0;
		while (set[i])
		{
			if (s1[end] == set[i])
			{
				end--;
				break ;
			}
			else if (set[i + 1] == 0)
				return (end);
			i++;
		}
	}
	return (end);
}

//retira os caracteres contidos em set
char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s2;
	int		cut;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = notcharset1(s1, set);
	end = notcharset2(s1, set);
	cut = end - start + 1;
	if (cut <= 0)
		return ("");
	s2 = (char *)malloc(sizeof(char) * (cut + 1));
	if (!s2)
		return (NULL);
	while (start <= end)
	{
		s2[i] = s1[start];
		start++;
		i++;
	}
	s2[i] = 0;
	return (s2);
}

// int main(void)
// {
// 	printf("%s\n", ft_strtrim("      ", " "));
// }