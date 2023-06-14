/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:39:18 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/14 19:40:28 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sorted(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_is_reverse_sorted(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
