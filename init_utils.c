/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:14:08 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/27 23:05:16 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_char_numbers(char **char_numbers)
{
	int	i;

	i = 0;
	while (char_numbers[i] != NULL)
	{
		free(char_numbers[i]);
		i++;
	}
	free(char_numbers);
}

t_node	*create_stack_one_arg(char **argv, t_node *stack, int i)
{
	int		j;
	char	**char_numbers;

	char_numbers = ft_split(argv[1], ' ');
	j = 0;
	while (char_numbers[j])
	{	
		create_node(&stack, ft_atoi_long(char_numbers[j]), i);
		if (stack->next)
			stack = stack->next;
		i++;
		j++;
	}
	free_char_numbers(char_numbers);
	return (stack);
}
