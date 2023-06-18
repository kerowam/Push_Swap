/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario42 <usuario42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:33 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/19 00:02:55 by usuario42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv) 
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;
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
	printf("check0\n");
	stack_a = init_stack(argc, argv);
	print_stack_value(stack_a);
	printf("check1\n");
	size = len_stack(stack_a);
	array = get_array(stack_a, size);
	printf("size: %d\n", size);
	printf("stack_a_position: %d\n", stack_a->position);
	printf("check2\n");
	position_min_value = get_position_min_value(stack_a);
	printf("position_min_value: %d\n", position_min_value);
	printf("check3\n");
	move_min_value_up(&stack_a, &stack_b, position_min_value);
	printf("check4\n");
	//length_array = get_length_array(stack_a, size);
	//printf("check5\n");
	//print_array(length_array, size);
	//printf("check6\n");
	//max_length_array_position = get_max_length_array_position(length_array,
	//		size);
	//printf("check7\n");
	//subsequence = get_subsequence(stack_a, size);
	//printf("check8\n");
	//print_array(subsequence, size);
	//printf("check9\n");
	//first_moves(&stack_a, &stack_b, max_length_array_position, subsequence);
	//printf("check10\n");
	//print_stack_value(stack_a);
	//print_stack_value(stack_b);
	return (0);
}
