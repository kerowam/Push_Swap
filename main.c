/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:33 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/09 17:14:20 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv) 
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_a;
	int		size_b;
	int 	*length_array;
	int 	*subsequence;
	int		*array;
	int		position_min_value;
	int 	max_length_array_position;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		put_error();
		return (0);
	}
	//printf("check0\n");
	stack_a = init_stack(argc, argv);
	//print_stack_value(stack_a);
	//while(stack_a->prev)
	//n	stack_a = stack_a->prev;
	//printf("check00\n");
	//rra(&stack_a);
	//printf("check00\n");	
	//print_stack_value(stack_a);
	//ra(&stack_a);
	//print_stack_value(stack_a);
	//printf("check1\n");
	//pb(&stack_a, &stack_b);
	//pb(&stack_a, &stack_b);
	//pb(&stack_a, &stack_b);
	//print_stack_value(stack_a);
	//print_stack_value(stack_b);
	//sa(&stack_a);
	//sb(&stack_b);
	//print_stack_value(stack_a);
	//print_stack_value(stack_b);
	//ss(&stack_a, &stack_b);
	//print_stack_value(stack_a);
	//print_stack_value(stack_b);
	//ra(&stack_a);
	//rb(&stack_b);
	//rr(&stack_a, &stack_b);
	//print_stack_value(stack_a);
	//print_stack_value(stack_b);
	//rra(&stack_a);
	//rrb(&stack_b);
	//rrr(&stack_a, &stack_b);
	//print_stack_value(stack_a);
	//print_stack_value(stack_b);
	//pa(&stack_a, &stack_b);
	//pa(&stack_a, &stack_b);
	//pa(&stack_a, &stack_b);
	//print_stack_value(stack_a);
	//printf("checking empty stack_b\n");
	//print_stack_value(stack_b);
	//printf("check1.2\n");
	size_a = len_stack(stack_a);
	array = get_array(stack_a, size_a);
	//printf("size: %d\n", size);
	//printf("stack_a_position: %d\n", stack_a->position);
	//printf("check2\n");
	position_min_value = get_position_min_value(stack_a);
	//printf("position_min_value: %d\n", position_min_value);
	//printf("check3\n");
	move_min_value_up(&stack_a, position_min_value);
	print_stack_value(stack_a);
	printf("check4\n");
	length_array = get_length_array(stack_a, size_a);
	//printf("check5\n");
	print_array(length_array, size_a);
	//printf("check6\n");	
	max_length_array_position = get_max_length_array_position(length_array, size_a);
	//printf("check7\n");
	subsequence = get_subsequence(stack_a, size_a);
	//printf("check8\n");
	print_array(subsequence, size_a);
	printf("check9\n");
	first_moves(&stack_a, &stack_b, max_length_array_position, subsequence, size_a);
	print_stack_value(stack_a);
	print_stack_value(stack_b);
	size_a = len_stack(stack_a);
	size_b = len_stack(stack_b);
	calculate_cost_b(&stack_b, size_b);
	printf("check10\n");
	calculate_cost_a(&stack_a, &stack_b, size_a);
	print_stack_value(stack_b);
	//printf("stack_a_position: %d\n", stack_a->position);
	//printf("stack_b_position: %d\n", stack_b->position);
	return (0);
}
