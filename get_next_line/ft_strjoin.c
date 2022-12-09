/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:33:51 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/09 16:23:48 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//ADAPTADO - COPIA ATE NEW LINE - junta duas strings
char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == 0)
		return (0);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = 0;
	//free(s1);
	return (s3);
}
/* 
int	main(void)
{
	printf("%s\n", ft_strjoin("bruno", "levi"));
}
 */