/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:29 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/08 17:21:02 by gfredes-         ###   ########.fr       */
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
	//update_position(stack);
}

t_node	*delete_up(t_node **stack)
{
	t_node	*tmp;

	while ((*stack)->prev)
		*stack = (*stack)->prev;
	tmp = malloc(sizeof(t_node));
	if (!tmp)
	{
		printf("Error: empty stack\n");
		return (NULL);
	}
	tmp = *stack;
	//printf("head->value: %d\n", (*head)->value);
	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	} else 
	{
		*stack = NULL;
	}
		
	//printf("tmp->value: %d\n", tmp->value);
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	insert_down(t_node **stack, t_node *node)
{
	//t_node	**last;

	//print_stack_value(*stack);
	//printf("node->value: %d\n", node->value);
	/**last = malloc(sizeof(t_node));
	if (!last)
	{
		return ;
	}*/
	//*last = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		//printf("last->value: %d\n", (*stack)->value);
	}
	if (!stack)
	{
		//printf("check insert_down 1\n");
		insert_up(stack, node);
		return ;
	}
	else
	{
		//printf("check insert_down 2\n");
		//printf("node->value: %d\n", node->value);
		(*stack)->next = node;
		node->prev = *stack;
		node->next = NULL;
		//*last = node;
	}
	while ((*stack)->prev)
	{
		*stack = (*stack)->prev;
		//printf("last->value: %d\n", (*stack)->value);
	}
	//update_position(stack);
}

t_node	*delete_down(t_node **stack)
{
	t_node	*tmp;

	while ((*stack)->next)
		*stack = (*stack)->next;
	//printf("last->position: %d\n", (*stack)->position);
	tmp = malloc(sizeof(t_node));
	if (!*stack)
	{
		printf("Error: empty stack\n");
		return (NULL);
	}
	/*if (!(*last)->next)
	{
		return (delete_up(last));
	}*/
	tmp = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}	

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