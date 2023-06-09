/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:31:01 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/08 23:31:01 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_stack(int argc, char **argv)
{
	t_node	*stack;
	int		i;
	char **numbers;

	i = 1;
	stack = NULL;
	check_args(argc, argv);
	if (argc == 2) {
		numbers = ft_split(argv[1], ' ');
		while (numbers[i])
		{	
			insert_up(&stack, ft_atoi(numbers[i]));
			i++;
		}
	} else if (argc > 2) {
		while (i < argc)
		{
			insert_up(&stack, ft_atoi(argv[i]));
			i++;
		}
	}
	check_duplicates(stack);
	
	return (stack);
}

void check_numbers(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) || (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])) || (argv[i][j] == '+' && !ft_isdigit(argv[i][j + 1])) || argv[i][j] != ' ')
				put_error();
			else if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
				put_error();
			j++;
		}
		i++;
	}
}

void check_duplicates(t_node *stack) {
	t_node *tmp;
	t_node *tmp2;

	tmp = stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				put_error();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}


void check_args(int argc, char **argv)
{
	if (argc < 2)
		put_error();
	else {
		check_numbers(argc, argv);
	}
}

void	print_stack(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	printf("Stack:\n");
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}