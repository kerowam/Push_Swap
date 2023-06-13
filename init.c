/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:31:01 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/13 17:24:45 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_stack(int argc, char **argv)
{
	t_node	*stack;
	int		i;
	char	**char_numbers;

	i = 1;
	stack = NULL;

	if (argc == 2)
	{
		char_numbers = ft_split(argv[1], ' ');
		while (char_numbers[i])
		{	
			insert_down(&stack, ft_atoi(char_numbers[i]));
			stack->position = i;
			i++;
		}
	}
	else if (argc > 2)
	{
		while (i < argc)
		{
			insert_down(&stack, ft_atoi(argv[i]));
			stack->position = i;
			i++;
		}
	}
	return (stack);
}

static void	get_index_sorted(t_node *stack)
{
	int	size;
	int	*array;
	int	i;

	i = 0;
	size = len_stack(stack);
	printf("size: %d\n", size);
	printf("\n");
	array = get_array(stack, size);
	print_array(array, size);
	printf("\n");
	sort_array(array, size);
	print_array(array, size);
	printf("\n");
	while (i < size)
	{
		if (array[i] == stack->value)
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
	printf("check8\n");
	free(array);
}

t_node	*init_stack(int argc, char **argv)
{
	t_node	*stack;

	stack = NULL;
	check_args(argc, argv);
	printf("check1\n");
	stack = create_stack(argc, argv);
	print_stack(stack);
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
	printf("check7\n");

	return (stack);
}
