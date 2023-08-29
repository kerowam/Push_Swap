/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:28:35 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/29 21:53:19 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_or_less(t_node **stack_a, size_t size)
{
	int	position_min_value;

	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		return ;
	}
	else if (size == 3)
	{
		sort_three(stack_a);
	}
	update_position(stack_a);
	return ;
}

void	sort_three(t_node **stack_a)
{
	while (!check_is_sorted(*stack_a))
	{
		if ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value
			> (*stack_a)->next->next->value)
		{
			ra(stack_a);
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
		}	
		else if ((*stack_a)->value < (*stack_a)->next->value
			&& (*stack_a)->value < (*stack_a)->next->next->value)
		{
			ra(stack_a);
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
			rra(stack_a);
		}
		else
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
			else
				rra(stack_a);
		}
	}
}

void	reverse_sort_three(t_node **stack_a, size_t size)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->value < (*stack_a)->next->value)
			sa(stack_a);
		return ;
	}
	else if (size == 3)
	{
		if ((*stack_a)->value < (*stack_a)->next->value)
			sa(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->next->value)
			rra(stack_a);
		else if ((*stack_a)->value < (*stack_a)->next->next->value)
			ra(stack_a);
		return ;
	}
}


void	sort_four(t_node **stack_a, t_node **stack_b, size_t size)
{
	if (size == 4 && check_is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_three(stack_a);
	update_positions(stack_a, stack_b);
	if (size == 4)
		final_moves(stack_a, stack_b, 3, 1);
	else if (size == 5)
		final_moves(stack_a, stack_b, 3, 2);
	update_positions(stack_a, stack_b);
}

void	sort_five(t_node **stack_a, t_node **stack_b, size_t size)
{
	if (check_is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b, size);
}

void	sort_five_bubble(t_node **stack_a, size_t size)
{
	int	min_value;

	min_value = get_min_value(stack_a);
	while (!check_is_sorted(*stack_a))
	{
		if ((*stack_a)->value > (*stack_a)->next->value
			&& (*stack_a)->next->value != min_value)
			sa(stack_a);
		rra(stack_a);
	}
}
