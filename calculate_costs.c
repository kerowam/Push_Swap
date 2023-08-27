/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:44:40 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/27 14:03:20 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost_b(t_node **stack_b, int size_b)
{
	t_node	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (size_b % 2 == 0)
		{
			if (tmp->position <= size_b / 2)
				tmp->cost_b = tmp->position - 1;
			else if (tmp->position > size_b / 2)
				tmp->cost_b = tmp->position - size_b -1;
		}
		else
		{
			if (tmp->position <= (size_b / 2) + 1)
				tmp->cost_b = tmp->position - 1;
			else if (tmp->position > size_b / 2)
				tmp->cost_b = tmp->position - size_b - 1;
		}
		tmp = tmp->next;
	}
}

void	calculate_target_position(t_node **stack_a,
			t_node **stack_b, int position_min_value)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		index_sorted_head;
	int		index_sorted_last;
	int		index_sorted_min_value;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	index_sorted_head = tmp_a->index_sorted;
	index_sorted_min_value = get_index_sortd_min_val(tmp_a, position_min_value);
    tmp_a = move_pointer_to_last(tmp_a);
	index_sorted_last = tmp_a->index_sorted;
	while (tmp_b)
	{
		tmp_a = *stack_a;
		tmp_b->target_position = 0;
		if (tmp_b->index_sorted < index_sorted_min_value)
			tmp_b->target_position = position_min_value;
		else if (tmp_b->index_sorted > index_sorted_min_value)
		{
			set_target_positions(tmp_a, tmp_b, position_min_value,
                    index_sorted_min_value);
		}
		tmp_b = tmp_b->next;
	}
}

void	calculate_cost_a(t_node **stack_a, t_node **stack_b, int size_a)
{
	t_node	*tmp_b;

	tmp_b = *stack_b;
	while (tmp_b)
	{
		if (tmp_b->target_position <= size_a / 2)
			tmp_b->cost_a = tmp_b->target_position - 1;
		else
			tmp_b->cost_a = tmp_b->target_position - size_a - 1;
		tmp_b = tmp_b->next;
	}
}

void	calculate_total_cost(t_node **stack_b)
{
	t_node	*tmp;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	while (tmp)
	{
		cost_a = tmp->cost_a;
		cost_b = tmp->cost_b;
		if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
			select_cost(tmp, cost_a, cost_b);
		else
		{
			if (cost_a < 0)
				cost_a *= -1;
			if (cost_b < 0)
				cost_b *= -1;
			tmp->total_cost = cost_a + cost_b + 1;
		}
		tmp = tmp->next;
	}
}

int	select_index_minimum_cost(t_node **stack_b)
{
	t_node	*tmp;
	int		minimun_cost;
	int		index_sorted;

	minimun_cost = 50000;
	tmp = *stack_b;
	while (tmp)
	{
		if (minimun_cost > tmp->total_cost)
		{
			minimun_cost = tmp->total_cost;
			index_sorted = tmp->index_sorted;
		}
		else if (minimun_cost == tmp->total_cost)
		{
			if (tmp->index_sorted > index_sorted)
			{
				minimun_cost = tmp->total_cost;
				index_sorted = tmp->index_sorted;
			}
		}
		tmp = tmp->next;
	}
	return (index_sorted);
}
