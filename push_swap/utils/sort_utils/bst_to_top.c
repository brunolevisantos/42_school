/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:58:54 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/10 15:11:38 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	bst_to_top(t_stack **stacka, t_stack **stackb, t_stack *best, int flag)
{
	t_stack	*curr;
	t_stack	**stack;

	stack = 0;
	if (flag == 1)
		stack = stacka;
	if (flag == 2)
		stack = stackb;
	curr = *stack;
	if (list_size(&best) < list_size(stack) / 2)
	{
		while (curr != best)
		{
			rev_rotate(stacka, stackb, flag);
			curr = *stack;
		}
	}
	else
	{
		while (curr != best)
		{
			rotate(stacka, stackb, flag);
			curr = *stack;
		}
	}
}
