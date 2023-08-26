/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:02:09 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/26 13:35:11 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_sortd_min_val(t_node *tmp, int position_min_value)
{
	int		index_sorted_min_value;
	t_node	*tmp2;

	tmp2 = tmp;
	while (tmp->next)
	{
		if (tmp->position == position_min_value)
			index_sorted_min_value = tmp->index_sorted;
		tmp = tmp->next;
	}
	if (tmp->position == position_min_value)
		index_sorted_min_value = tmp->index_sorted;
	return (index_sorted_min_value);
}

void	set_target_position_case1(t_node *tmp_a, t_node *tmp_b,
			int index_sorted_min_value)
{
	while (tmp_a->index_sorted != index_sorted_min_value)
		tmp_a = tmp_a->next;
	while (tmp_b->target_position == 0 && tmp_a)
	{
		if (tmp_a->index_sorted > tmp_b->index_sorted)
			tmp_b->target_position = tmp_a->position;
		else
			tmp_a = tmp_a->next;
	}
}

void	set_target_position_case2(t_node *tmp_a, t_node *tmp_b,
			int position_min_value)
{
	while (tmp_b->target_position == 0
		&& tmp_a->position < position_min_value)
	{
		if (tmp_a->index_sorted < tmp_b->index_sorted)
			tmp_a = tmp_a->next;
		else
			tmp_b->target_position = tmp_a->position;
	}
}

void	set_target_position_case3(t_node *tmp_a, t_node *tmp_b)
{
	while (tmp_b->index_sorted > tmp_a->index_sorted && tmp_a->next)
		tmp_a = tmp_a->next;
	tmp_b->target_position = tmp_a->position;
}

void	set_target_positions(t_node *tmp_a, t_node *tmp_b,
			int position_min_value, int index_sorted_min_value)
{
	int		index_sorted_head;
	int		index_sorted_last;

	index_sorted_head = tmp_a->index_sorted;
	tmp_a = move_pointer_to_last(tmp_a);
	index_sorted_last = tmp_a->index_sorted;
	tmp_a = move_pointer_to_head(tmp_a);
	if (tmp_b->index_sorted < index_sorted_head
		&& tmp_b->index_sorted < index_sorted_last)
		set_target_position_case1(tmp_a, tmp_b, index_sorted_min_value);
	else if (tmp_b->index_sorted < index_sorted_head
		&& tmp_b->index_sorted > index_sorted_last)
		tmp_b->target_position = 1;
	else if (tmp_b->index_sorted > index_sorted_head
		&& tmp_b->index_sorted > index_sorted_last
		&& index_sorted_head != index_sorted_min_value)
		set_target_position_case2(tmp_a, tmp_b, position_min_value);
	else if (index_sorted_head == index_sorted_min_value)
		set_target_position_case3(tmp_a, tmp_b);
}
