/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:27:15 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/02 16:10:02 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	int	tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;


	tmp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = tmp;
	write(1, "sa\n", 3);
	update_position(stack_a);
	return ;
}

void	sb(t_node **stack_b)
{
	int	tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;


	tmp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = tmp;
	write(1, "sb\n", 3);
	update_position(stack_b);
	return ;
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
	update_position(stack_a);
	update_position(stack_b);
	return ;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_b)
		return ;

	insert_up(stack_a, delete_up(stack_b));
	write(1, "pa\n", 3);
	update_position(stack_a);
	update_position(stack_b);
	return ;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a)
		return;

	insert_up(stack_b, delete_up(stack_a));
	write(1, "pb\n", 3);
	update_position(stack_a);
	update_position(stack_b);
	return;
}
