/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:33:34 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/26 15:34:09 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_b)
		return ;
	insert_up(stack_a, delete_up(stack_b));
	write(1, "pa\n", 3);
	return ;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a)
		return ;
	insert_up(stack_b, delete_up(stack_a));
	write(1, "pb\n", 3);
	return ;
}
