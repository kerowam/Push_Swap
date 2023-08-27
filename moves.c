/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:38:51 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/27 13:12:21 by gfredes-         ###   ########.fr       */
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
	}
	else if (position_min_value <= (size / 2))
	{
		moves = position_min_value - 1;
		while (moves > 0)
		{
			ra(stack);
			moves--;
		}
	}
	update_position(stack);
}

void	first_moves(t_node **stack_a, t_node **stack_b,
			int max_length_array_position, int *subsequence)
{
	int			position_target;
	t_node		*tmp;
	int			size;

	size = len_stack(*stack_a);
	tmp = *stack_a;
	tmp = move_pointer_to_last(tmp);
	position_target = max_length_array_position;
	while (size > 0)
	{
		if (tmp->position != position_target)
		{
			tmp = tmp->prev;
			rra(stack_a);
			pb(stack_a, stack_b);
		}
		else if (tmp->position == position_target)
		{
			tmp = tmp->prev;
			rra(stack_a);
			position_target = subsequence[position_target -1] + 1;
		}
			size--;
	}
	update_positions(stack_a, stack_b);
}

void	move_minimum_cost(t_node **stack_a, t_node **stack_b,
			int index_sorted_minimum_cost)
{
	t_node	*tmp_b;

	tmp_b = *stack_b;
	while (tmp_b && tmp_b->index_sorted != index_sorted_minimum_cost)
		tmp_b = tmp_b->next;
	while (tmp_b->cost_a != 0 || tmp_b->cost_b != 0)
	{
		if ((tmp_b->cost_a > 0 && tmp_b->cost_b > 0)
			|| (tmp_b->cost_a < 0 && tmp_b->cost_b < 0))
			double_similar_rotates_moves(stack_a, stack_b, tmp_b);
		else if ((tmp_b->cost_a > 0 && tmp_b->cost_b < 0)
			|| (tmp_b->cost_a < 0 && tmp_b->cost_b > 0))
			double_different_rotates_moves(stack_a, stack_b, tmp_b);
		else
			single_rotates_moves(stack_a, stack_b, tmp_b);
	}
	pa(stack_a, stack_b);
	update_positions(stack_a, stack_b);
}

void	final_moves(t_node **stack_a, t_node **stack_b, int size_a, int size_b)
{
	int		index_sorted_minimum_cost;
	int		position_min_value;

	while (size_b > 0)
	{
		position_min_value = get_position_min_value(stack_a);
		calculate_cost_b(stack_b, size_b);
		calculate_target_position(stack_a, stack_b, position_min_value);
		calculate_cost_a(stack_a, stack_b, size_a);
		calculate_total_cost(stack_b);
		index_sorted_minimum_cost = select_index_minimum_cost(stack_b);
		move_minimum_cost(stack_a, stack_b, index_sorted_minimum_cost);
		size_b -= 1;
		size_a += 1;
	}
	while ((*stack_a)->prev)
		*stack_a = (*stack_a)->prev;
	position_min_value = get_position_min_value(stack_a);
	move_min_value_up(stack_a, position_min_value);
	while ((*stack_a)->prev)
		*stack_a = (*stack_a)->prev;
}
