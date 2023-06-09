/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:33 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/06 23:20:33 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv) {
	t_node	*stack_a;
	t_node	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2) {
		put_error();
		return 0;
	}
	stack_a = init_stack(argc, argv);
	print_stack(stack_a);

	return 0;
}