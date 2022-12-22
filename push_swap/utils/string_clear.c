/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:44:41 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/22 16:17:05 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	string_clear(char **string)
{
	int	i;

	i = 0;
	if (!string)
		return ;
	while (string[i])
		free(string[i++]);
	free(string);
}
