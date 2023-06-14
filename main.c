/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:33 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/14 18:17:13 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv) 
{
	t_node	**stack_a;
	t_node	**stack_b;
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
	stack_a = init_stack(argc, argv);
	//printf("check\n");
	size = len_stack(stack_a);
	print_stack(stack_a);
	position_min_value = get_position_min_value(stack_a, size);
	move_min_value_up(**stack_a, position_min_value, size);
	array = get_array(stack_a, size);
	length_array = get_length_array(stack_a, size);
	print_array(length_array, size);
	max_length_array_position = get_max_length_array_position(length_array, size);
	subsequence = get_subsequence(stack_a, size);
	print_array(subsequence, size);
	first_moves(**stack_a, **stack_b, max_length_array_position, subsequence, size);
	print_stack(stack_a);
	print_stack(stack_b);

	return (0);
}