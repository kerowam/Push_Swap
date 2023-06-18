/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:38:51 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/15 22:44:59 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_value_up(t_node **stack_a, t_node **stack_b, int position_min_value)
{
	int		size;
	int		*array;
	int		*length_array;
	int		*subsequence;
	int		max_length_array_position;

	size = len_stack(*stack_a);
	array = get_array(*stack_a, size);
	length_array = get_length_array(*stack_a, size);
	max_length_array_position = get_max_length_array_position(length_array, size);
	subsequence = get_subsequence(*stack_a, size);
	first_moves(stack_a, stack_b, max_length_array_position, subsequence);
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
