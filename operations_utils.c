/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:29 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/19 03:43:05 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_up(t_node **head, t_node *node)
{

	if (!*head)
	{
		*head = node;
		node->next = NULL;
		node->prev = NULL;
		return ;
	}
	else
	{
		node->next = *head;
		node->prev = NULL;
		(*head)->prev = node;
		*head = node;
	}
	update_position(head);
}

t_node	*delete_up(t_node **head)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
	{
		printf("Error: empty stack\n");
		return (NULL);
	}
	tmp = *head;
	*head = (*head)->next;
	return (tmp);
}

void	insert_down(t_node **stack, t_node *node)
{
	t_node	**last;

	*last = malloc(sizeof(t_node));
	*last = *stack;
	while ((*last)->next)
		*last = (*last)->next;
	if (!last)
	{
		insert_up(last, node);
		return ;
	}
	else
	{
		(*last)->next = node;
		node->prev = *last;
		node->next = NULL;
		*last = node;
	}
	update_position(stack);
}

t_node	*delete_down(t_node **last)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!*last)
	{
		printf("Error: empty stack\n");
		return (NULL);
	}
	if (!(*last)->next)
	{
		return (delete_up(last));
	}
	tmp = *last;
	*last = (*last)->prev;
	(*last)->next = NULL;
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