/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:31:01 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/12 23:43:36 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_stack(int argc, char **argv)
{
	t_node *stack;
	int i;
	char **char_numbers;

	i = 1;
	stack = NULL;

	if (argc == 2) {
		char_numbers = ft_split(argv[1], ' ');
		while (char_numbers[i])
		{	
			insert_up(&stack, ft_atoi(char_numbers[i]));
			stack->position = i;
			i++;
		}
	} else if (argc > 2) {
		while (i < argc)
		{
			insert_up(&stack, ft_atoi(argv[i]));
			stack->position = i;
			i++;
		}
	}
	return (stack);
}

static void	get_index_sorted(t_node *stack)
{
	int size;
	int *array;
	int i;

	i = 0;
	size = len_stack(stack);
	array = get_array(stack, size);
	sort_array(array, size);
	while (i < size)
	{
		if (array[i] == stack->value) {
			stack->index_sorted = i + 1;
			i++;
			while(stack)
				stack = stack->prev;
		} else {
			stack = stack->next;
		}
	}
}

t_node	*init_stack(int argc, char **argv)
{
	t_node	*stack;
	
	stack = NULL;
	check_args(argc, argv);
	printf("check1\n");
	stack = create_stack(argc, argv);
	printf("check2\n");
	check_duplicates(stack);
	printf("check3\n");
	get_min_value(stack);
	printf("check4\n");
	check_is_sorted(stack);
	printf("check5\n");
	check_is_reverse_sorted(stack);
	printf("check6\n");
	get_index_sorted(stack);

	return (stack);
}
