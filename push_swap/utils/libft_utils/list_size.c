/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:11:14 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/06 11:18:01 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	list_size(t_stack **stack)
{
	int	i;
	t_stack	*curr;
	
	i = 0;
	curr = *stack;
	while (curr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}