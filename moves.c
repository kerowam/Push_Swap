/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:38:51 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/09 00:29:30 by gfredes-         ###   ########.fr       */
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
	update_position(stack);
}

void	first_moves(t_node **stack_a, t_node **stack_b, int max_length_array_position, int *subsequence, int size)
{

	int 		position_target;
	t_node		*tmp;
	//t_node		*last;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
	{
		return;
	}
	//last = malloc(sizeof(t_node));
	//if (!last)
	//{
	//	return;
	//}
	tmp = *stack_a;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	//last = tmp;
	position_target = max_length_array_position;
	while (size > 0)
	{
		if (tmp->position != position_target)
		{
			tmp = tmp->prev;
			rra(stack_a);
			pb(stack_a, stack_b);
			//last = tmp;
			size--;
		}
		else if (tmp->position == position_target)
		{
			tmp = tmp->prev;
			rra(stack_a);
			//last = tmp;
			position_target = subsequence[position_target -1] + 1;
			size--;
		}
	}
	update_position(stack_a);
	update_position(stack_b);
}
