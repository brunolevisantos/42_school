/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:11:19 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/20 10:28:23 by bde-seic         ###   ########.fr       */
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

#endif