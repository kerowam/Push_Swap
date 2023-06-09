/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:48:26 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/09 20:48:26 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void check_duplicates(t_node *stack)
{
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
	else
	{
		check_numbers(argc, argv);
	}
}

int check_min_number(t_node *stack)
{
	t_node *tmp;
	int min;

	tmp = stack;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}