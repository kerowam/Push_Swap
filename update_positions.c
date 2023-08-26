/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:41:37 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/24 00:44:54 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_position(t_node **head)
{
	int		i;
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	tmp = *head;
	i = 1;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

void	update_positions(t_node **stack_a, t_node **stack_b)
{
	update_position(stack_a);
	update_position(stack_b);
}
