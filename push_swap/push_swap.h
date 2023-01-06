/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:11:19 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/06 11:18:08 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

int		main(int argc, char **argv);
char	**ft_split(char const *s, char c);
void	add_node(t_stack **stacka, int num, int *error);
int		atoi_two(char *string, int *error);
void	list_clear(t_stack **stack, int *error);
void	swap(t_stack **stacka, t_stack **stackb, int flag);
void	rotate(t_stack **stacka, t_stack **stackb, int flag);
void	rev_rotate(t_stack **stacka, t_stack **stackb, int flag);
void	push(t_stack **stackfrom, t_stack **stackto, int flag);
void	string_clear(char **string);
void	run_algorithm(t_stack **stacka, t_stack **stackb);
void	*ft_calloc(size_t nelem, size_t elsize);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		list_size(t_stack **stack);

#endif