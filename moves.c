/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:38:51 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/13 13:43:54 by gfredes-         ###   ########.fr       */
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

void	move_minimum_cost(t_node **stack_a, t_node **stack_b, int index_sorted_minimum_cost)
{
	//t_node  *tmp_a;
    t_node  *tmp_b;
	int		cost_a;
	int		cost_b;

    //tmp_a = malloc(sizeof(t_node));
    tmp_b = malloc(sizeof(t_node));
    if(/*!tmp_a || */!tmp_b)
        return;
    //tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_b && tmp_b->index_sorted != index_sorted_minimum_cost)
		tmp_b = tmp_b->next;
	cost_a = tmp_b->cost_a;
	cost_b = tmp_b->cost_b;
	while(cost_a != 0 || cost_b != 0)
	{
		if (cost_a > 0 && cost_b > 0)
		{
			rr(stack_a, stack_b);
			cost_a -= 1;
			cost_b -= 1;
		} else if (cost_a < 0 && cost_b < 0)
		{
			rrr(stack_a, stack_b);
			cost_a += 1;
			cost_b += 1;
		} else if (cost_a > 0 && cost_b < 0)
		{
			ra(stack_a);
			rrb(stack_b);
			cost_a -= 1;
			cost_b += 1;
		} else if (cost_a < 0 && cost_b > 0)
		{
			rb(stack_b);
			rra(stack_a);
			cost_a += 1;
			cost_b -= 1;
		} else if (cost_a > 0)
		{
			ra(stack_a);
			cost_a -= 1;
		} else if (cost_a < 0)
		{
			rra(stack_a);
			cost_a += 1;
		} else if (cost_b > 0)
		{
			rb(stack_b);
			cost_b -= 1;
		} else if (cost_b < 0)
		{
			rrb(stack_b);
			cost_b += 1;
		} 
	}
	pa(stack_a, stack_b);
	update_position(stack_a);
	update_position(stack_b);
}

void	final_moves(t_node **stack_a, t_node **stack_b,int size_a, int size_b)
{
	int		index_sorted_minimum_cost;
	int		position_min_value;

	while (size_b > 0)
	{
		calculate_cost_b(stack_b, size_b);
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
