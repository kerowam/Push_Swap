/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:52:02 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/09 20:52:02 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;

	insert_down(stack_a, delete_up(stack_a));
	write(1, "ra\n", 3);
}

void rb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;

	insert_down(stack_b, delete_up(stack_b));
	write(1, "rb\n", 3);
}

void rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
