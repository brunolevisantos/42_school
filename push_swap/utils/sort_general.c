/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:20:02 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/09 15:38:55 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	avg(t_stack **stack)
{
	int		total;
	t_stack	*curr;

	curr = *stack;
	total = 0;
	while (curr)
	{
		total += curr->num;
		curr = curr->next;
	}
	return (total / (list_size(stack)));
}

void	below_avg_to_b(t_stack **stacka, t_stack **stackb)
{
	t_stack	*curr;

	curr = *stacka;
	while (list_size(stacka) > 3)
	{
		curr = *stacka;
		if (curr->num < avg(stacka))
		{
			push(stacka, stackb, 2);
			if ((*stackb)->num < avg(stackb))
				rotate(0, stackb, 2);
		}
		else
			rotate(stacka, stackb, 1);
	}	
}

void	best_to_top(t_stack **stacka, t_stack **stackb, t_stack *best, int flag)
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

t_stack	*best_neighbour(t_stack **stacka, t_stack **stackb)
{
	t_stack	*ca;
	t_stack	*best;
	int		diff;

	diff = INT_MAX;
	ca = *stacka;
	best = 0;
	while (ca)
	{
		if (ca->num > (*stackb)->num && ca->num - (*stackb)->num < diff)
		{
			best = ca;
			diff = ca->num - (*stackb)->num;
		}
		ca = ca->next;
	}
	if (!best)
		best = min_node(stacka);
	return (best);
}

void	sort_general(t_stack **stacka, t_stack **stackb)
{
	below_avg_to_b(stacka, stackb);
	sort_three(stacka, stackb, 1);
	while (*stackb)
	{
		best_to_top(stacka, stackb, max_node(stackb), 2);
		best_to_top(stacka, stackb, best_neighbour(stacka, stackb), 1);
		push(stackb, stacka, 1);
	}
	best_to_top(stacka, stackb, min_node(stacka), 1);
}
