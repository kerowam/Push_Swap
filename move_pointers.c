/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pointers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:48:04 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/24 00:54:48 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*move_pointer_to_last(t_node *pointer)
{
	while (pointer->next)
		pointer = pointer->next;
	return (pointer);
}

t_node	*move_pointer_to_head(t_node *pointer)
{
	while (pointer->prev)
		pointer = pointer->prev;
	return (pointer);
}
