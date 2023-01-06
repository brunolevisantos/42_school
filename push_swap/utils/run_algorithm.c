/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:28:53 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/06 13:35:23 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//retirar quando pronto
void	print_stack(t_stack **stacka, t_stack **stackb)
{
	t_stack	*curr;

	curr = *stacka;
	while (curr)
	{
		printf("Stack a: %d\n", (curr)->num);
		curr = curr->next;
	}
	curr = *stackb;
	while (curr)
	{
		printf("Stack b: %d\n", (curr)->num);
		curr = curr->next;
	}
}

int	sorted(t_stack **stacka)
{
	t_stack	*curr;
	
	curr = *stacka;
	while (curr->next)
	{
		if (curr->num < curr->next->num)
			curr = curr->next;
		else
			return (0);
	}
	return (1);
}

void	sort_three(t_stack **stacka, t_stack **stackb, int flag)
{
	t_stack	*curr;

	curr = *stacka;
	if (curr->num > curr->next->num && curr->next->next->num > curr->num)
		swap(stacka, stackb, flag);
	else if (curr->num > curr->next->num && curr->next->num > curr->next->next->num)
	{
		swap(stacka, stackb, flag);
		rev_rotate(stacka, stackb, flag);
	}
	else if (curr->next->num < curr->next->next->num && curr->next->next->num < curr->num)
		rotate(stacka, stackb, flag);
	else if (curr->num < curr->next->num && curr->num > curr->next->next->num)
		rev_rotate(stacka, stackb, flag);
	else if (curr->num < curr->next->num && curr->next->num > curr->next->next->num)
	{
		swap(stacka, stackb, flag);
		rotate(stacka, stackb, flag);
	}
}

/* void	all_to_b(t_stack **stacka, t_stack **stackb)
{
	int		max_one;
	int		max_two;
	int		max_three;
	t_stack	*curr;

	curr = (*stacka)->next->next->next;
	max_one = (*stacka)->num;
	max_two = (*stacka)->next->num;
	max_three = (*stacka)->next->next->num;
	while (curr)
	{
		if (curr->num > max_one)

		else if (curr)
	}

}
 */
void	run_algorithm(t_stack **stacka, t_stack **stackb)
{
	print_stack(stacka, stackb);
	if (sorted(stacka))
		return ;
	if (list_size(stacka) == 2 && !sorted(stacka))
		swap(stacka, stackb, 1);
	else if (list_size(stacka) == 3 && !sorted(stacka))
		sort_three(stacka, stackb, 1);
	print_stack(stacka, stackb);
}
