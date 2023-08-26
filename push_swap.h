/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:20:21 by gfredes-          #+#    #+#             */
/*   Updated: 2023/08/26 14:06:55 by gfredes-         ###   ########.fr       */
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
#include "./libft/libft.h"

typedef struct s_node
{
	int				value;
	int				position;
	int				index_sorted;
	int				target_position;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void		create_node(t_node **last, int value, int i);
void		insert_up(t_node **head, t_node *node);
t_node		*delete_up(t_node **head);
void		insert_down(t_node **last, t_node *node);
t_node		*delete_down(t_node **last);
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
void		print_stack_value(t_node *stack);
void		sort_three(t_node **stack_a, size_t size);
t_node		*init_stack(int argc, char **argv);
void		check_numbers(int argc, char **argv);
void		check_duplicates(t_node *stack);
void		check_args(int argc, char **argv);
int			get_min_value(t_node **stack);
int			check_is_sorted(t_node *stack);
int			check_is_reverse_sorted(t_node *stack);
int			len_stack(t_node *stack);
int			*get_array(t_node *stack, int size);
int			*sort_array(int *array, int size);
int			get_position_min_value(t_node **stack);
int			*init_length_array(int size);
int			*get_length_array(t_node *stack, int size);
int			get_max_length_array_position(int *length_array, int size);
int			*get_subsequence(t_node *stack, int size, int *array,
				int *length_array);
void		print_array(int *array, int size);
void		check_int(long nb);
int			ft_atoi_long(const char *str);
void		move_min_value_up(t_node **stack, int position_min_value);
void		first_moves(t_node **stack_a, t_node **stack_b,
				int max_length_array_position, int *subsequence);
void		print_stack_position(t_node *stack);
void		update_position(t_node **head);
void		calculate_cost_b(t_node **stack_b, int size_b);
void		calculate_cost_a(t_node **stack_a, t_node **stack_b, int size_a);
void		calculate_total_cost(t_node **stack_b);
int			select_index_minimum_cost(t_node **stack_b);
void		move_minimum_cost(t_node **stack_a, t_node **stack_b,
				int index_sorted_minimum_cost);
void		final_moves(t_node **stack_a, t_node **stack_b, int size_a,
				int size_b);
void		calculate_target_position(t_node **stack_a, t_node **stack_b,
				int position_min_value);
void		update_positions(t_node **stack_a, t_node **stack_b);
t_node		*move_pointer_to_last(t_node *pointer);
t_node		*move_pointer_to_head(t_node *pointer);
void		double_similar_rotates_moves(t_node **stack_a, t_node **stack_b,
				t_node *tmp);
void		double_different_rotates_moves(t_node **stack_a, t_node **stack_b,
				t_node *tmp);
void		single_rotates_moves(t_node **stack_a, t_node **stack_b,
				t_node *tmp);
t_node		*create_stack_one_arg(char **argv, t_node *stack, int i);
int			get_index_sortd_min_val(t_node *tmp, int position_min_value);
void		set_target_position_case1(t_node *tmp_a, t_node *tmp_b,
				int index_sorted_min_value);
void		set_target_position_case2(t_node *tmp_a, t_node *tmp_b,
				int position_min_value);
void		set_target_position_case3(t_node *tmp_a, t_node *tmp_b);
void		set_target_positions(t_node *tmp_a, t_node *tmp_b,
				int position_min_value, int index_sorted_min_value);
void		select_cost(t_node *tmp, int cost_a, int cost_b);

#endif