/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:31:01 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/27 22:09:05 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_up_create(t_node **head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->position = 1;
	if (!*head)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return ;
	}
	else
	{
		new_node->next = *head;
		new_node->prev = NULL;
		(*head)->prev = new_node;
		*head = new_node;
	}
}

void	create_node(t_node **last, int value, int i)
{
	t_node	*new_node;
	t_node	*last_node;

	if (!*last)
	{
		insert_up_create(last, value);
		return ;
	}

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->position = i;
	new_node->next = NULL;
	last_node = *last;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_node;
	new_node->prev = last_node;
}

static t_node	*create_stack(int argc, char **argv)
{
	t_node	*stack;
	int		i;
	int		j;

	i = 1;
	stack = NULL;
	if (argc == 2)
		stack = create_stack_one_arg(argv, stack, i);
	else if (argc > 2)
	{
		while (i < argc)
		{
			create_node(&stack, ft_atoi_long(argv[i]), i);
			if (stack->next)
				stack = stack->next;
			stack->position = i;
			i++;
		}
	}
	while (stack->prev != NULL)
		stack = stack->prev;
	return (stack);
}

static void	get_index_sorted(t_node *stack)
{
	int	size;
	int	*array;
	int	*sorted_array;
	int	i;

	i = 0;
	size = len_stack(stack);
	array = get_array(stack, size);
	sorted_array = sort_array(array, size);
	while (i < size)
	{
		if (sorted_array[i] == stack->value)
		{
			stack->index_sorted = i + 1;
			i++;
			while (stack->prev)
				stack = stack->prev;
		}
		else
		{
			stack = stack->next;
		}
	}
	free(array);
}

t_node	*init_stack(int argc, char **argv)
{
	t_node	*stack;

	stack = NULL;
	check_args(argc, argv);
	stack = create_stack(argc, argv);
	check_duplicates(stack);
	get_min_value(&stack);
	check_is_sorted(stack);
	check_is_reverse_sorted(stack);
	get_index_sorted(stack);
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}
