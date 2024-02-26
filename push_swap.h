/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:11:33 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/26 19:27:25 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

//----------RANGE INFO----------//
typedef struct s_range_info
{
	int		start;
	int		end;
	int		size;
	int		*index_arr;
}			t_range_info;

//----------STACKS INFO----------//
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

//----------STRUCT MAIN----------//
typedef struct s_pushswap
{
	t_stack			*a;
	t_stack			*b;
	t_range_info	*r;
	int				range;
}			t_pushswap;

//----------ARGUMENTS----------//
int		is_number(int nb);
int		only_number(char *s);
int		verify_argv(char **argv);
int		is_int(char **argv);
int		is_duplicated(char **argv);

//----------STACK----------//
int		push_new(t_stack **stack, int value);
int		in_stack(t_pushswap *pushswap, int argc, char **argv);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);

//----------ALGORITHMS----------//
void	first_algorithm(t_pushswap *ps);
void	second_algorithm(t_pushswap *ps);
void	third_algorithm(t_pushswap *ps, int size);

//----------OPERATIONS----------//
int		sa(t_pushswap *pushswap);
int		sb(t_pushswap *pushswap);
int		ss(t_pushswap *pushswap);

int		pa(t_pushswap *pushswap);
int		pb(t_pushswap *pushswap);

int		ra(t_pushswap *pushswap);
int		rb(t_pushswap *pushswap);
int		rr(t_pushswap *pushswap);

int		rra(t_pushswap *pushswap);
int		rrb(t_pushswap *pushswap);
int		rrr(t_pushswap *pushswap);

//----------OPERATIONS UTILS----------//
int		swap(t_stack **stack);
int		push(t_stack **stack_from, t_stack **stack_to);
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);

//----------ARRAY UTILS----------//
int		*stack_to_array(t_stack *stack);
int		*bubblesort(int *stack, int size);
void	set_index(t_stack *stack, int *array, int size);

//----------RANGE UTILS----------//
int		set_range(int size);
t_range_info	*start_range(t_pushswap *ps, int size);
void	remove_from_range(t_pushswap *ps);
void	next_range(t_pushswap *ps, int size);

//----------UTILS----------//
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		print_stacks(t_pushswap *ps);

#endif //PUSH_SWAP
