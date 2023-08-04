/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:38:51 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/04 22:10:59 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_value_up(t_node **stack_a, t_node **stack_b, int position_min_value)
{
	int	size;
	int	moves;

	size = len_stack(*stack_a);

	if (position_min_value > (size / 2))
	{
		moves = position_min_value - size + 1;
		while (moves > 0)
		{
			rra(stack_a);
			moves--;
		}
	} else if (position_min_value <= (size / 2))
	{
		moves = position_min_value - 1;
		while (moves > 0)
		{
			ra(stack_a);
			moves--;
		}
	}
}

void	first_moves(t_node **stack_a, t_node **stack_b, int max_length_array_position, int *subsequence)
{
	t_node *last;
	int 		position_target;

	while (*stack_a)
	{
		*stack_a = (*stack_a)->next;
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
