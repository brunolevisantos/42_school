/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:34:10 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/12 11:25:49 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "get_next_line/get_next_line.h"

int		main(int argc, char **argv);
void	run_checker(t_stack **stacka, t_stack **stackb);
int		my_strcmp(char *s1, char *s2);
int		checker_rotate(t_stack **stacka, t_stack **stackb, int flag);
void	checker_swap(t_stack **stacka, t_stack **stackb, int flag);
void	checker_rev_rotate(t_stack **stacka, t_stack **stackb, int flag);
void	checker_push(t_stack **stackfrom, t_stack **stackto);

#endif
