/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:50:07 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/13 17:27:13 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	print_stack(t_node *stack)
{
	t_node *tmp;

	tmp = stack;
	printf("Stack:\n");
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

int	len_stack(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	print_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
	printf("\n");
	return;
}
