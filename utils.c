/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:50:07 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/27 16:21:00 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	len_stack(t_node *stack)
{
	t_node	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	free(tmp);
	return (i);
}

int	ft_atoi_long(const char *str)
{
	int		i;
	int		neg;
	long	long_nb;
	int		nb;

	i = 0;
	neg = 1;
	long_nb = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		long_nb = long_nb * 10 + (str[i] - '0');
		i++;
	}
	long_nb *= neg;
	check_int(long_nb);
	nb = long_nb;
	return (nb);
}

int	*check_malloc(int *pointer)
{
	if (!pointer)
		return (NULL);
}

void	free_tmp(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

//ONLY TO CHECK. REMOVE!!!
void	print_stack_value(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	printf("Stack:\n");
	while (tmp)
	{
		printf("stack_value: %d\n", tmp->value);
		printf("stack_position: %d\n", tmp->position);
		printf("index_sorted: %d\n", tmp->index_sorted);
		printf("stack->cost_a: %d\n", tmp->cost_a);
		printf("stack->cost_b: %d\n", tmp->cost_b);
		printf("total_cost: %d\n", tmp->total_cost);
		printf("target_position: %d\n\n", tmp->target_position);
		tmp = tmp->next;
	}
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
	return ;
}

void	print_stack_position(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	printf("Stack:\n");
	while (tmp)
	{
		printf("stack_position: %d\n", tmp->position);
		tmp = tmp->next;
	}
}
