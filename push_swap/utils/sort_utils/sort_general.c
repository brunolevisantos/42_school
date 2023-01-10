/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:20:02 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/10 15:11:57 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_general(t_stack **stacka, t_stack **stackb)
{
	below_avg_to_b(stacka, stackb);
	sort_three(stacka, stackb, 1);
	while (*stackb)
	{
		bst_to_top(stacka, stackb, least_cost(stacka, stackb), 2);
		bst_to_top(stacka, stackb, best_neighbour(stacka, stackb), 1);
		push(stackb, stacka, 1);
	}
	bst_to_top(stacka, stackb, min_node(stacka), 1);
}
