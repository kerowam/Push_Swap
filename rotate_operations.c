/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:52:02 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/26 22:16:29 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	insert_down(stack_a, delete_up(stack_a));
	write(1, "ra\n", 3);
	return ;
}

void	rb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	insert_down(stack_b, delete_up(stack_b));
	write(1, "rb\n", 3);
	return ;
}

static void	ra_unwrite(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	insert_down(stack_a, delete_up(stack_a));
	return ;
}

static void	rb_unwrite(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	insert_down(stack_b, delete_up(stack_b));
	return ;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra_unwrite(stack_a);
	rb_unwrite(stack_b);
	write(1, "rr\n", 3);
	return ;
}
