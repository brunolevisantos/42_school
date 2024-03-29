/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:17:08 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/13 12:28:24 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_node(t_stack **stacka, int num, int *error, char **string)
{
	t_stack	*curr;
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	node -> num = num;
	node -> next = 0;
	if (!*stacka)
		*stacka = node;
	curr = *stacka;
	while (curr)
	{
		if (curr->num == num && curr != node)
		{
			*error = 1;
			list_clear(stacka, error);
			string_clear(string);
			exit(1);
		}
		if (!curr->next && curr != node)
			curr->next = node;
		curr = curr->next;
	}
}
