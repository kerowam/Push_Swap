/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:19:19 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/24 20:06:37 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_similar_rotates_moves(t_node **stack_a, t_node **stack_b,
			t_node *tmp)
{
	if (tmp->cost_a > 0 && tmp->cost_b > 0)
	{
		rr(stack_a, stack_b);
		tmp->cost_a -= 1;
		tmp->cost_b -= 1;
	}
	else if (tmp->cost_a < 0 && tmp->cost_b < 0)
	{
		rrr(stack_a, stack_b);
		tmp->cost_a += 1;
		tmp->cost_b += 1;
	}
}

void	double_different_rotates_moves(t_node **stack_a, t_node **stack_b,
			t_node *tmp)
{
	if (tmp->cost_a > 0 && tmp->cost_b < 0)
	{
		ra(stack_a);
		rrb(stack_b);
		tmp->cost_a -= 1;
		tmp->cost_b += 1;
	}
	else if (tmp->cost_a < 0 && tmp->cost_b > 0)
	{
		rb(stack_b);
		rra(stack_a);
		tmp->cost_a += 1;
		tmp->cost_b -= 1;
	}
}

void	single_rotates_moves(t_node **stack_a, t_node **stack_b,
			t_node *tmp)
{
	if (tmp->cost_a > 0)
	{
		ra(stack_a);
		tmp->cost_a -= 1;
	}
	else if (tmp->cost_a < 0)
	{
		rra(stack_a);
		tmp->cost_a += 1;
	}
	else if (tmp->cost_b > 0)
	{
		rb(stack_b);
		tmp->cost_b -= 1;
	}
	else if (tmp->cost_b < 0)
	{
		rrb(stack_b);
		tmp->cost_b += 1;
	}
}
