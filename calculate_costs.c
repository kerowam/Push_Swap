/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:44:40 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/10 01:37:57 by gfredes-         ###   ########.fr       */
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

void    calculate_cost_a(t_node **stack_a, t_node **stack_b, int size_a)
{
    t_node  *tmp_a;
    t_node  *tmp_b;
    int     i;

    tmp_a = malloc(sizeof(t_node));
    tmp_b = malloc(sizeof(t_node));
    if(!tmp_a || !tmp_b)
        return;
    tmp_b = *stack_b;
    while (tmp_b)
    {
        tmp_a = *stack_a;
        i = 0;
        while (tmp_a && tmp_a->index_sorted < tmp_b->index_sorted)
        {
            tmp_a = tmp_a->next;
            i++;
        }
        if (i < size_a / 2)
            tmp_b->cost_a = i;
        else
            tmp_b->cost_a = size_a - i;
        tmp_b = tmp_b->next;
    }
}

void    calculate_total_cost(t_node **stack_b)
{
    t_node  *tmp;

    tmp = malloc(sizeof(t_node));
    if(!tmp)
        return;
    tmp = *stack_b;
    while(tmp)
    {
        tmp->total_cost = tmp->cost_a + tmp->cost_b + 1;
        tmp = tmp->next;
    }
}

int select_index_minimum_cost(t_node **stack_b)
{
    t_node  *tmp;
    int     minimun_cost;
    int     index_sorted;

    minimun_cost = 50000;
    tmp = malloc(sizeof(t_node));
    if(!tmp)
        return (0);
    tmp = *stack_b;
    while(tmp)
    {
        if (minimun_cost > tmp->total_cost)
        {
            minimun_cost = tmp->total_cost;
            index_sorted = tmp->index_sorted;
        } 
        tmp = tmp->next;
    }
    return (index_sorted);
}