/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:33 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/13 18:06:24 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv) {
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;
	int 	*length_array;
	int 	*subsequence;
	int		*array;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		put_error();
		return (0);
	}
	stack_a = init_stack(argc, argv);
	printf("check\n");
	size = len_stack(stack_a);
	print_stack(stack_a);
	array = get_array(stack_a, size);
	length_array = get_length_array(stack_a, size);
	print_array(length_array, size);
	subsequence = get_subsequence(stack_a, size);
	print_array(subsequence, size);

	return (0);
}