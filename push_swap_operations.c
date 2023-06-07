/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:27:15 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/07 02:27:15 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;

	int tmp;

	tmp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = tmp;
}

void sb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;

	int tmp;

	tmp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = tmp;
}

void ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void pa(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_b)
		return;

	insert_up(stack_a, delete_up(stack_b));
}

void pb(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a)
		return;

	insert_up(stack_b, delete_up(stack_a));
}

void ra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;

	insert_down(stack_a, delete_up(stack_a));
}

void rb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;

	insert_down(stack_b, delete_up(stack_b));
}

void rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}