/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:11:19 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/21 15:31:43 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/ft_printf/ft_printf.h" //ver como procurar libft e printf
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_stack;

int	main(int argc, char **argv);
void    add_node(t_stack **stacka, int num);
int atoi_two(char *string, t_stack **stacka);
void	list_clear(t_stack **stack);
void	swap(t_stack **stacka, t_stack **stackb, int flag);
void	rotate(t_stack **stacka, t_stack **stackb, int flag);
void	rev_rotate(t_stack **stacka, t_stack **stackb, int flag);

#endif