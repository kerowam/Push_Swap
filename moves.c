/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:38:51 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/08 15:28:37 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_value_up(t_node **stack, int position_min_value)
{
	int	size;
	int	moves;

	size = len_stack(*stack);

	if (position_min_value > (size / 2))
	{
		moves = size - position_min_value + 1;
		while (moves > 0)
		{
			rra(stack);
			moves--;
		}
	} else if (position_min_value <= (size / 2))
	{
		moves = position_min_value - 1;
		while (moves > 0)
		{
			ra(stack);
			moves--;
		}
	}
}

void	first_moves(t_node **stack_a, t_node **stack_b, int max_length_array_position, int *subsequence)
{

	int 		position_target;

	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
	}
	position_target = max_length_array_position;
	while (*stack_a)
	{
		if ((*stack_a)->position != position_target)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			*stack_a = (*stack_a)->prev;
		}
		else if ((*stack_a)->position == position_target)
		{
			rra(stack_a);
			*stack_a = (*stack_a)->prev;
			position_target = subsequence[position_target];
		}
	}
}
