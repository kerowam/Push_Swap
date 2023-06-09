/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:21:46 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/09 21:21:46 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *get_array(t_node *stack, int size)
{
	int *array;
	int i;

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

int *sort_array(int *array, int size)
{
	int i;
	int j;
	int tmp;

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