/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:27:15 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/29 18:29:30 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	int	tmp;
	int tmp_index_sorted;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->value;
	tmp_index_sorted = (*stack_a)->index_sorted;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->index_sorted = (*stack_a)->next->index_sorted;
	(*stack_a)->next->value = tmp;
	(*stack_a)->next->index_sorted = tmp_index_sorted;
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_node **stack_b)
{
	int	tmp;
	int tmp_index_sorted;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->value;
	tmp_index_sorted = (*stack_b)->index_sorted;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->index_sorted = (*stack_b)->next->index_sorted;
	(*stack_b)->next->value = tmp;
	(*stack_b)->next->index_sorted = tmp_index_sorted;
	write(1, "sb\n", 3);
	return ;
}

static void	sa_unwrite(t_node **stack_a)
{
	int	tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = tmp;
	return ;
}

static void	sb_unwrite(t_node **stack_b)
{
	int	tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = tmp;
	return ;
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa_unwrite(stack_a);
	sb_unwrite(stack_b);
	write(1, "ss\n", 3);
	return ;
}
