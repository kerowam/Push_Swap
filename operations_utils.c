/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:29 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/06 23:20:29 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_up(t_node **head, int value) {
	t_node *new_node;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node) {
		printf("Error: malloc failed\n");
		return;
	}
	if (!*head) {
		new_node->value = value;
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return;
	} else {
		new_node->value = value;
		new_node->next = *head;
		new_node->prev = NULL;
		(*head)->prev = new_node;
		*head = new_node;
	}
}

int	delete_up (t_node **head) {
	if (!*head) {
		printf("Error: empty stack\n");
		return -1;
	}
	
	t_node *tmp;
	int value;
	
	tmp = *head;
	value = tmp->value;
	*head = tmp->next;
	if (*head)
		(*head)->prev = NULL;
	free(tmp);
	return value;
}

void	insert_down(t_node **last, int value) {
	if (!*head) {
		insert_up(head, value);
		return;
	}

	t_node *new_node;
	t_node *last_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node) {
		printf("Error: malloc failed\n");
		return;
	}
	new_node->value = value;
	new_node->next = NULL;
	last_node = *last;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_node;
	new_node->prev = last_node;
}
	
int	delete_down(t_node **last) {
	if (!*head) {
		printf("Error: empty stack\n");
		return -1;
	}
	if (!(*head)->next) {
		return delete_up(head);
	}
	t_node *tmp;
	t_node *last_node;
	int value;
	
	last_node = *last;
	while (last_node->next)
		last_node = last_node->next;
	tmp = last_node;
	value = tmp->value;
	last_node = tmp->prev;
	if (last_node)
		last_node->next = NULL;
	else
		*last = NULL;
	free(tmp);
	return value;
}	
