/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 01:57:21 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/27 15:30:53 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_length_array(t_node *stack, int size)
{
	int	*array;
	int	*length_array;
	int	i;
	int	j;

	i = 0;
	j = 0;
	array = get_array(stack, size);
	length_array = init_length_array(size);
	while (i < size)
	{
		while (j < i)
		{
			if (array[j] < array[i] && length_array[j] + 1 > length_array[i])
				length_array[i] = length_array[j] + 1;
			j++;
		}
		j = 0;
		i++;
	}
	free(array);
	return (length_array);
}

int	get_max_length_array_position(int *length_array, int size)
{
	int	i;
	int	max_length;
	int	max_length_array_position;

	i = 0;
	max_length = 1;
	max_length_array_position = 1;
	while (i < size)
	{
		if (max_length < length_array[i])
		{
			max_length = length_array[i];
			max_length_array_position = i + 1;
		}
		i++;
	}
	return (max_length_array_position);
}

int	*get_subsequence(t_node *stack, int size, int *array, int *length_array)
{
	int	*subsequence;
	int	i;
	int	j;

	i = 1;
	subsequence = malloc(sizeof(int) * size);
	check_malloc(subsequence);
	while (i < size)
	{
		j = 0;
		subsequence[i] = 0;
		while (j < i)
		{
			if (array[j] < array[i] && length_array[j] + 1 > length_array[i])
			{
				length_array[i] = length_array[j] + 1;
				subsequence[i] = j;
			}
			else if (j == i - 1 && subsequence[i] == 0 && array[j] > array[i])
				subsequence[i] = i;
			j++;
		}
		i++;
	}
	return (subsequence);
}

void	lis(t_node *stack_a, t_node *stack_b, int size_a, int size_b)
{
	int		*length_array;
	int		*length_array_init;
	int		*subsequence;
	int		*array;
	int		max_length_array_position;

	array = get_array(stack_a, size_a);
	length_array = get_length_array(stack_a, size_a);
	max_length_array_position = get_max_length_array_position(length_array,
			size_a);
	free(length_array);
	length_array_init = init_length_array(size_a);
	subsequence = get_subsequence(stack_a, size_a, array, length_array_init);
	first_moves(&stack_a, &stack_b, max_length_array_position, subsequence);
	free(subsequence);
	size_a = len_stack(stack_a);
	size_b = len_stack(stack_b);
	final_moves(&stack_a, &stack_b, size_a, size_b);
	free(array);
	free(length_array_init);
}
