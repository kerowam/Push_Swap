/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:21:46 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/27 01:12:22 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_array(t_node *stack, int size)
{
	int	*array;
	int	i;

	i = 0;
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (array);
}

int	*sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

int	get_min_value(t_node **stack)
{
	t_node	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_position_min_value(t_node **stack)
{
	int		min_value;
	t_node	*tmp;

	tmp = *stack;
	min_value = get_min_value(stack);
	while (tmp)
	{
		if (tmp->value == min_value)
			return (tmp->position);
		tmp = tmp->next;
	}
	return (0);
}

int	*init_length_array(int size)
{
	int	*length_array;
	int	i;

	i = 0;
	length_array = malloc(sizeof(int) * size);
	if (!length_array)
		return (NULL);
	while (i < size)
	{
		length_array[i] = 1;
		i++;
	}
	return (length_array);
}
