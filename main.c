/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:33 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/27 00:54:10 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/*void check_leaks(void)
{
	system("leaks a.out");
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
	//atexit(check_leaks);
	return (0);
}
