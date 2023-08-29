/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:33 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/30 00:40:47 by gfredes-         ###   ########.fr       */
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

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = init_stack(argc, argv);
	size_a = len_stack(stack_a);
	if (size_a <= 3)
		sort_three_or_less(&stack_a, size_a);
	else if (size_a == 4)
		sort_four(&stack_a, &stack_b, size_a);
	else if (size_a == 5)
		sort_five(&stack_a, &stack_b, size_a);
	else
		lis(stack_a, stack_b, size_a, size_b);
	while (stack_a->prev)
		stack_a = stack_a->prev;
	//print_stack_value(stack_a);
	free_tmp (stack_a);
	free_tmp (stack_b);
	return (0);
}
