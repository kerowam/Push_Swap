/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:48:26 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/24 01:16:06 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' && !(ft_isdigit(argv[i][j + 1])))
				|| (argv[i][j] == '+' && !(ft_isdigit(argv[i][j + 1]))))
			{
				printf("Error1: %c%c\n", argv[i][j], argv[i][j + 1]);
				put_error();
			}
			else if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			{
				printf("Error2: %d\n", ft_atoi(argv[i]));
				put_error();
			}
			j++;
		}
		i++;
	}
}

void	check_duplicates(t_node *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

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

void	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		return ;
	}
	else
	{
		check_numbers(argc, argv);
	}
}

void	check_int(long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		put_error();
}
