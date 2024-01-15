/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:11:33 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/15 15:14:05 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

// operations utils

int	swap(t_stack **stack);
int	push(t_stack **stack_from, t_stack **stack_to);
int	rotate(t_stack **stack);
int	reverse_rotate(t_stack **stack);

// operations

int	sa(t_data *data);
int	sb(t_data *data);
int	ss(t_data *data);

int	pa(t_data *data);
int	pb(t_data *data);

int	ra(t_data *data);
int	rb(t_data *data);
int	rr(t_data *data);

int	rra(t_data *data);
int	rrb(t_data *data);
int	rrr(t_data *data);

// init

int	init_data(t_data *data, int argc, char *argv[]);

// utils

int	is_sorted(t_stack *stack);

// debug

int	print_stacks(t_data *data);

#endif //PUSH_SWAP
