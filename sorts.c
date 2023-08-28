/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:28:35 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/28 00:55:24 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a, size_t size)
{
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
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		if ((*stack_a)->value < (*stack_a)->next->next->value)
			rra(stack_a);
		else if ((*stack_a)->value > (*stack_a)->next->next->value)
			ra(stack_a);
		return ;
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
