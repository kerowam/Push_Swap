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

int *get_subsequence(t_node *stack)
{
	int *array;
	int *length_array;
	int *subsequence;
	int size;
	int i;
	int j;

	i = 1;
	j = 0;
	size = len_stack(stack);
	array = get_array(stack, size);
	length_array = init_lenght_array(size);
	subsequence = malloc(sizeof(int) * size);
	if (!subsequence)
		return (NULL);
	while(i < size)
	{
		while (j < i)
		{
			if (array[j] < array[i] && length_array[j] + 1 > length_array[i])
			{
				length_array[i] = length_array[j] + 1;
				subsequence[i] = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (subsequence);
}