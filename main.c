/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:33 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/25 21:18:01 by gfredes-         ###   ########.fr       */
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
	int		*length_array;
	int		*length_array_init;
	int 	*subsequence;
	int		*array;
	int		position_min_value;
	int 	max_length_array_position;
	int		index_sorted_minimum_cost;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		return (0);
	}
	stack_a = init_stack(argc, argv);
	//print_stack_value(stack_a);
	size_a = len_stack(stack_a);
	array = get_array(stack_a, size_a);
	//print_array(array, size_a);
	//position_min_value = get_position_min_value(&stack_a);
	//move_min_value_up(&stack_a, position_min_value);
	length_array = get_length_array(stack_a, size_a);
	print_array(length_array, size_a);
	max_length_array_position = get_max_length_array_position(length_array, size_a);
	length_array_init = init_length_array(size_a);
	subsequence = get_subsequence(stack_a, size_a, array, length_array_init);
	print_array(subsequence, size_a);
	first_moves(&stack_a, &stack_b, max_length_array_position, subsequence);
	print_stack_value(stack_a);
	size_a = len_stack(stack_a);
	size_b = len_stack(stack_b);
	calculate_cost_b(&stack_b, size_b);
	position_min_value = get_position_min_value(&stack_a);
	calculate_target_position(&stack_a, &stack_b, position_min_value);
	calculate_cost_a(&stack_a, &stack_b, size_a);
	calculate_total_cost(&stack_b);
	print_stack_value(stack_b);
	final_moves(&stack_a, &stack_b, size_a, size_b);
	print_stack_value(stack_a);
	print_stack_value(stack_b);
	return (0);
}
