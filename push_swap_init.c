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

t_node	*init_stack(int argc, char **argv)
{
	t_node	*stack;
	int		i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		insert_up(&stack, ft_atoi(argv[i]));
		i++;
	}
	return (stack);
}



void	print_stack(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	printf("Stack:\n");
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}