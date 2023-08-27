/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:33 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/27 16:23:08 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/*void check_leaks(void)
{
	system("leaks push_swap");
}*/

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
	lis(stack_a, stack_b, size_a, size_b);
	while (stack_a->prev)
		stack_a = stack_a->prev;
	free_tmp (stack_a);
	free_tmp (stack_b);
	return (0);
}

	//atexit(check_leaks);