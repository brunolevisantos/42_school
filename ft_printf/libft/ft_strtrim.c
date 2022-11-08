/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:09:13 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/03 14:59:26 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//retira os caracteres contidos em set
int	notcharset1(const char *s1, const char *set)
{
	int	start;
	int	i;

	start = 0;
	if (set[0] == '\0')
		return (start);
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
	if (set[0] == '\0')
		return (end);
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

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s2;
	int		cut;
	int		i;
	int		start;
	int		end;

	i = 0;
	if (s1[0] == '\0')
		return (ft_calloc(1, sizeof(char)));
	start = notcharset1(s1, set);
	end = notcharset2(s1, set);
	cut = end - start + 1;
	if (cut <= 0)
		return ((char *)ft_calloc(1, 1));
	s2 = (char *)ft_calloc((cut + 1), sizeof(char));
	if (!s2)
		return (NULL);
	while (start <= end)
	{
		s2[i] = s1[start];
		start++;
		i++;
	}
	return (s2);
}

/* int	main(void)
{
	printf("%s\n", ft_strtrim("123", ""));
}
 */