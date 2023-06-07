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

void	sa(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;

	int tmp;

	tmp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;

	int tmp;

	tmp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_b)
		return;

	insert_up(stack_a, delete_up(stack_b));
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a)
		return;

	insert_up(stack_b, delete_up(stack_a));
	write(1, "pb\n", 3);
}

void	ra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;

	insert_down(stack_a, delete_up(stack_a));
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;

	insert_down(stack_b, delete_up(stack_b));
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}

void	rra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;

	insert_up(stack_a, delete_down(stack_a));
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;

	insert_up(stack_b, delete_down(stack_b));
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
