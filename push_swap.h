/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:21 by gfredes-          #+#    #+#             */
/*   Updated: 2023/06/06 23:20:21 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

typedef struct s_node
{
	int value;
	int position;
	int index_sorted;
	int target_position;
	int cost_a;
	int cost_b;
	int total_cost;
	struct s_node *next;
	struct s_node *prev;
} t_node;

void		insert_up(t_node **head, int value);
int			delete_up(t_node **head);
void		insert_down(t_node **head, int value);
int			delete_down(t_node **head);
void		sa(t_node **stack_a);
void		sb(t_node **stack_b);
void		ss(t_node **stack_a, t_node **stack_b);
void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_a, t_node **stack_b);
void		ra(t_node **stack_a);
void		rb(t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);
void		rra(t_node **stack_a);
void		rrb(t_node **stack_b);
void		rrr(t_node **stack_a, t_node **stack_b);
void		put_error(void);
void 		print_stack(t_node *stack);
void 		sort_three(t_node **stack_a);
t_node	*init_stack(int argc, char **argv);
void 		check_numbers(int argc, char **argv);
void 		check_duplicates(t_node *stack);
void 		check_args(int argc, char **argv);
int 		get_min_value(t_node *stack);
int 		check_is_sorted(t_node *stack);
int 		check_is_reverse_sorted(t_node *stack);
int			len_stack(t_node *stack);
int 		*get_array(t_node *stack, int size);
int 		*sort_array(int *array, int size);
int 		get_position_min_value(t_node *stack);
int 		*init_lenght_array(int size);

#endif