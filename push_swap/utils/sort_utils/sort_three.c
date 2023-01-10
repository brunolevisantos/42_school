/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:17:17 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/10 14:43:47 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_three(t_stack **stacka, t_stack **stackb, int flag)
{
	t_stack	*curr;

	curr = *stacka;
	if (curr->num > curr->next->num && curr->next->next->num > curr->num)
		swap(stacka, stackb, flag);
	else if (curr->num > curr->next->num \
	&& curr->next->num > curr->next->next->num)
	{
		swap(stacka, stackb, flag);
		rev_rotate(stacka, stackb, flag);
	}
	else if (curr->next->num < curr->next->next->num \
	&& curr->next->next->num < curr->num)
		rotate(stacka, stackb, flag);
	else if (curr->num < curr->next->num && curr->num > curr->next->next->num)
		rev_rotate(stacka, stackb, flag);
	else if (curr->num < curr->next->num \
	&& curr->next->num > curr->next->next->num)
	{
		swap(stacka, stackb, flag);
		rotate(stacka, stackb, flag);
	}
}
