/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:37:01 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/03 14:46:16 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	atoi_two(char *string, int *error)
{
	int			i;
	int			sign;
	long int	y;

	i = 0;
	sign = 1;
	y = 0;
	if (string == 0)
		return (0);
	if (string[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (string[i])
	{
		if (string[i] < '0' || string[i] > '9')
		{
			*error = 1;
			break ;
		}
		else
			y = y * 10 + (string[i++] - '0') * sign;
	}
	if (y < INT_MIN || y > INT_MAX)
		*error = 1;
	return ((int)y);
}
