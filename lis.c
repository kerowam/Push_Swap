/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 01:57:21 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/10 01:57:21 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_length_array(t_node *stack, int size) {
	int *array;
	int *length_array;
	int i;
	int j;

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

int *get_subsequence(t_node *stack, int *length_array, int size)
{
	int *subsequence;
	int max_length;
	int max_length_array_position;
	int i;
	int j;

	i = 1;
	j = 0;
	max_length = 1;
	max_length_array_position = 1;

	subsequence = malloc(sizeof(int) * size + 1);
	if (!subsequence)
		return (NULL);
	while(i < size - 1)
	{
		while (j < i)
		{
			if (array[j] < array[i] && length_array[j] + 1 > length_array[i])
			{
				if (max_length < length_array[i])
				{
					max_length = length_array[i];
					max_length_array_position = i;
				}
				subsequence[i] = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	subsequence[i] = max_length_array_position;
	return (subsequence);
}
