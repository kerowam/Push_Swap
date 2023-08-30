/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:01:07 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/26 14:06:32 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_cost(t_node *tmp, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			tmp->total_cost = cost_a + 1;
		else
			tmp->total_cost = cost_b + 1;
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a < cost_b)
			tmp->total_cost = (cost_a - 1) * -1;
		else
			tmp->total_cost = (cost_b - 1) * -1;
	}
}
