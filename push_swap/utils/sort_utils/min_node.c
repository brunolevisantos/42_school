/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:12:35 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/10 15:00:22 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*min_node(t_stack **stack)
{
	t_stack	*min;
	t_stack	*curr;

	min = *stack;
	curr = *stack;
	while (curr)
	{
		if (curr->num < min->num)
			min = curr;
		curr = curr->next;
	}
	return (min);
}
