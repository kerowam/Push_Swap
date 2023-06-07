/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:28:35 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/07 19:28:35 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pivot_value(t_node **stack, int size)
{
	int	value;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		value = (*stack)->value;
		*stack = (*stack)->next;
		i++;
	}
	return (value);
}


void sort_three(t_node **stack_a)
{
	if (size == 1)
		return;
	else if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		return;
	}
	else if (size == 3)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		if ((*stack_a)->value < (*stack_a)->next->next->value)
			rra(stack_a);
		else if ((*stack_a)->value > (*stack_a)->next->next->value)
			ra(stack_a);
		return;
	}
}

void	quick_sort_a(t_node **stack_a, t_node **stack_b, int size)
{
	int	pivot_index;
	int pivot_value;
	int i;

	if (size <= 3) {
		sort_three(stack_a);
		return;
	}
	else if (size > 3 && size < 100) {
		pivot_index = size / 2;
		pivot_value = get_pivot_value(stack_a, size);
		i = 0;
		while (i < pivot_index)
		{
			if ((*stack_a)->value < pivot_value) {
				pb(stack_a, stack_b);
				i++;
			} else {
				ra(stack_a);
				i++;
			}
			stack_a = &(*stack_a)->next;
		}
		while (i < size) {
			if ((*stack_a)->value < pivot_value) {
				pb(stack_a, stack_b);
				i++;
			} else {
				ra(stack_a);
				i++;
			}
			stack_a = &(*stack_a)->next;
		}
		quick_sort_a(stack_a, stack_b, pivot_index);
	}
}
