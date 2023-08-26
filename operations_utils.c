/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:29 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/27 00:44:36 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_up(t_node **stack, t_node *node)
{
	if (!*stack)
	{
		*stack = node;
		node->next = NULL;
		node->prev = NULL;
		return ;
	}
	else
	{
		while ((*stack)->prev)
			*stack = (*stack)->prev;
		node->next = *stack;
		node->prev = NULL;
		(*stack)->prev = node;
		*stack = node;
	}
}

t_node	*delete_up(t_node **stack)
{
	t_node	*tmp;

	while ((*stack)->prev)
		*stack = (*stack)->prev;
	tmp = malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp = *stack;
	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	insert_down(t_node **stack, t_node *node)
{
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
	}
	if (!stack)
	{
		insert_up(stack, node);
		return ;
	}
	else
	{
		(*stack)->next = node;
		node->prev = *stack;
		node->next = NULL;
	}
	while ((*stack)->prev)
		*stack = (*stack)->prev;
}

t_node	*delete_down(t_node **stack)
{
	t_node	*tmp;

	while ((*stack)->next)
		*stack = (*stack)->next;
	tmp = malloc(sizeof(t_node));
	if (!*stack)
		return (NULL);
	tmp = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}	
