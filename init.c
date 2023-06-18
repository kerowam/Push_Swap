/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:31:01 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/19 01:28:59 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_up_create(t_node **head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		printf("Error: malloc failed\n");
		return ;
	}
	if (!*head)
	{
		new_node->value = value;
		new_node->position = 1;
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return ;
	}
	else
	{
		new_node->value = value;
		new_node->position = 1;
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
		printf("check\n");
		insert_up_create(last, value);
		return ;
	}

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		printf("Error: malloc failed\n");
		return ;
	}
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
	char	**char_numbers;

	i = 1;
	stack = NULL;
	if (argc == 2)
	{
		char_numbers = ft_split(argv[1], ' ');
		j = 0;
		while (char_numbers[j])
		{	
			printf("check_create_stack\n");
			create_node(&stack, ft_atoi_long(char_numbers[j]), i);
			printf("creating_stack->value: %d\n", stack->value);
			printf("creating_stack->position: %d\n", stack->position);
			i++;
			j++;
		}
	}
	else if (argc > 2)
	{
		while (i < argc)
		{
			create_node(&stack, ft_atoi_long(argv[i]), i);
			if (stack->next)
				stack = stack->next;
			printf("creating_stack->value: %d\n", stack->value);
			stack->position = i;
			printf("creating_stack->position: %d\n", stack->position);
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
	printf("size: %d\n", size);
	printf("\n");
	array = get_array(stack, size);
	print_array(array, size);
	printf("\n");
	sorted_array = sort_array(array, size);
	print_array(array, size);
	printf("\n");
	while (i < size)
	{
		if (sorted_array[i] == stack->value)
		{
			stack->index_sorted = i + 1;
			//printf("%d stack->index_sorted: %d\n", i, stack->index_sorted);
			//printf("stack->value: %d\n", stack->value);
			i++;
			while (stack->prev)
				stack = stack->prev;
		}
		else
		{
			stack = stack->next;
		}
	}
	//printf("check8\n");
	free(array);
}

t_node	*init_stack(int argc, char **argv)
{
	t_node	*stack;
	t_node	*tmp;

	stack = NULL;
	check_args(argc, argv);
	//printf("check1\n");
	stack = create_stack(argc, argv);
	print_stack_value(stack);
	//printf("check2\n");
	check_duplicates(stack);
	//printf("check3\n");
	get_min_value(stack);
	//printf("check4\n");
	check_is_sorted(stack);
	//printf("check5\n");
	check_is_reverse_sorted(stack);
	//printf("check6\n");
	get_index_sorted(stack);
	//printf("check7\n");
	while (stack->prev)
		stack = stack->prev;
	//printf("check8\n");
	return (stack);
}
