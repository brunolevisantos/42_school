/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:17:08 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/20 10:54:10 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    add_node(t_stack **stacka, int num)
{
    t_stack  *curr;
    t_stack  *node;
    
    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return (0);
    node -> num = num;
    node -> next = 0;
    if (!*stacka)
    {
        *stacka = node; //CONFIRMAR QUE ESTA BEM
        return ;
    }
    curr = *stacka; //CONFIRMAR QUE VOLTA AO PRIMEIRO NODE DA LISTA EM PROXIMAS ITERACOES
    while (curr)
    {
        if (curr -> num = num)
        {
            free (stacka); //CONFIRMAR QUE LIMPA TUDO
            write (2, "Error\n", 6);
            exit (0);
        }
        curr = curr -> next;
    }
    *stacka = node;
}