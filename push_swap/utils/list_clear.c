/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:35:56 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/22 21:37:25 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	list_clear(t_stack **stack, int *error)
{
	t_stack	*current;

	if (!*stack)
		return ;
	while (*stack != NULL)
	{
		current = (*stack)->next;
		free(*stack);
		*stack = current;
	}
/* 	printf("O valor do error e: %ls\n", error);
	error = 0; */
	if (error != NULL)
		write(2, "Error\n", 6);
}
