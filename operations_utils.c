/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:29 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/14 19:34:23 by gfredes-         ###   ########.fr       */
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
}

t_node	*delete_up(t_node **head)
{
	t_node	*tmp;

	if (!*head)
	{
		printf("Error: empty stack\n");
		return (NULL);
	}
	tmp = *head;
	*head = (*head)->next;
	return (tmp);
}

void	insert_down(t_node **last, t_node *node)
{
	if (!*last)
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
}

t_node	*delete_down(t_node **last)
{
	t_node	*tmp;

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
