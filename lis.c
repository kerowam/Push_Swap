/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 01:57:21 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/25 21:14:47 by gfredes-         ###   ########.fr       */
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
	if (!subsequence)
		return (NULL);
	while (i < size)
	{
		j = 0;
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
