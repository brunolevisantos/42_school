/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:10:52 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/09 23:11:18 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*max_node(t_stack **stack)
{
	t_stack	*max;
	t_stack	*curr;

	max = *stack;
	curr = *stack;
	while (curr)
	{
		if (curr->num > max->num)
			max = curr;
		curr = curr->next;
	}
	return (max);
}
