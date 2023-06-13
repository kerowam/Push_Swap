/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 01:57:21 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/13 18:26:09 by gfredes-         ###   ########.fr       */
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

int get_max_length_array_position(int *length_array, int size)
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
			max_length_array_position = i;
		}
		i++;
	}
	return (max_length_array_position);
}

int	*get_subsequence(int *array, int size)
{
	int	*subsequence;
	int *length_array;
	int	i;
	int	j;

	i = 1;
	j = 0;
	length_array = get_length_array(array, size);
	subsequence = malloc(sizeof(int) * size + 1);
	if (!subsequence)
		return (NULL);
	while (i < size)
	{
		printf("check_sub1\n");
		while (j < i)
		{
			printf("check_sub2\n");
			printf("array[j]: %d\n", array[j]);
			printf("array[i]: %d\n", array[i]);
			printf("length_array[j]: %d\n", length_array[j]);
			printf("length_array[i]: %d\n", length_array[i]);
			if (array[j] < array[i] && length_array[j] + 1 > length_array[i])
			{
				printf("check_sub3\n");
				subsequence[i] = j;
				printf("subsequence[%d]: %d\n", i, subsequence[i]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (subsequence);
}
