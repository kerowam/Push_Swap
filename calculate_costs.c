/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:44:40 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/09 14:58:38 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    calculate_cost_b(t_node **stack_b, int size_b)
{
    t_node  *tmp;

    tmp = malloc(sizeof(t_node));
    if(!tmp)
        return;
    tmp = *stack_b;
    while(tmp)
    {
        if (size_b % 2 == 0)
        {
            if(tmp->position <= size_b / 2)
                tmp->cost_b = tmp->position - 1;
            else if(tmp->position > size_b / 2)
                tmp->cost_b = size_b - tmp->position + 1;
        } else 
        {
            if(tmp->position <= (size_b / 2) + 1)
                tmp->cost_b = tmp->position - 1;
            else if(tmp->position > size_b / 2)
                tmp->cost_b = size_b - tmp->position + 1;
        }
        tmp = tmp->next;
    }
}