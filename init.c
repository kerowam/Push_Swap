/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:31:01 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/08 23:31:01 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_stack(int argc, char **argv)
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


t_node	*init_stack(int argc, char **argv)
{
	t_node	*stack;
	
	stack = NULL;
	check_args(argc, argv);
	stack = create_stack(argc, argv);
	check_duplicates(stack);
	
	return (stack);
}


