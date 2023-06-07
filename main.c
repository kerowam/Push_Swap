/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:33 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/06 23:20:33 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv) {
	t_node	*stack_a;
	t_node	*stack_b;
	char		**numbers;
	size_t	size;

	argv[0] = "push_swap";
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2) {
		printf("Error: no arguments\n");
		return 0;
	} else if (argc == 2) {
		numbers = ft_split(argv[1], ' ');
		int count = 0;
		while (numbers[count])
		{
			insert_up(&stack_a, ft_atoi(numbers[count]));
			count++;
		}
		size = count;
	} else if (argc > 2) {
		int arg = 1;
		size = argc - 1;
		while (arg < argc)
		{
			insert_up(&stack_a, ft_atoi(argv[arg]));
			arg++;
		}
	}
	
	

	return 0;
}