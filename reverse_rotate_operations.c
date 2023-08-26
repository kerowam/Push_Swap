/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:54:46 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/26 22:14:44 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;

	insert_up(stack_a, delete_down(stack_a));
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;

	insert_up(stack_b, delete_down(stack_b));
	write(1, "rrb\n", 4);
	return ;
}

static void	rra_unwrite(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;

	insert_up(stack_a, delete_down(stack_a));
	write(1, "rra\n", 4);
	return ;
}

static void	rrb_unwrite(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;

	insert_up(stack_b, delete_down(stack_b));
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra_unwrite(stack_a);
	rrb_unwrite(stack_b);
	write(1, "rrr\n", 4);
	return ;
}
