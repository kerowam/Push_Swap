/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:38:51 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/14 21:38:51 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_value_up(t_node **stack, int position_min_value, int size)
{
	if (position_min_value <= size / 2)
	{
		while ((*stack)->position != position_min_value)
			ra(stack);
	}
	else
	{
		while ((*stack)->position != position_min_value)
			rra(stack);
	}
}

void	first_moves(t_node **stack_a, t_node **stack_b, int max_length_array_position, int *subsequence, int size)
{
	t_node *last;
	int 		position_target;

	while (*stack_a)
	{
		*stack_a = stack_a->next;
	}
	last = *stack_a;
	position_target = max_length_array_position;
	while (last)
	{
		if (last->position != position_target)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			last = last->prev;
		}
		else if (last->position == position_target)
		{
			rra(stack_a);
			last = last->prev;
			position_target = subsequence[position_target];
		}
	}
}
