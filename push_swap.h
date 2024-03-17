/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:43:30 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/14 15:43:37 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

//----------STRUCT NODE----------//
typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
	int				value;
}			t_node;

//----------STRUCT STACK----------//
typedef struct s_stack
{
	t_node			*top;
	t_node			*bot;
	int				size;
}			t_stack;

//----------STRUCT MAIN----------//
typedef struct s_pushswap
{
	t_stack			*a;
	t_stack			*b;
}			t_pushswap;

//----------ARGUMENTS----------//
int				is_number(int nb);
int				only_number(char *s);
int				verify_argv(char **argv);
int				is_int(char **argv);
int				is_duplicated(char **argv);

//----------STACK----------//
void			put_in_stack(t_pushswap *pushswap, int argc, char **argv);
int				is_sorted(t_stack *stack);

//----------ALGORITHMS----------//
void			first_algorithm(t_pushswap *ps);
void			second_algorithm(t_pushswap *ps);
void			third_algorithm(t_pushswap *ps);

//----------THIRD UTILS----------//
int				push_and_rotate(t_pushswap *ps, int size);
int				inside_range(t_pushswap *ps, int start, int end);
int				is_chunk_sent(int *pushed_value, int start, int end);
void			update_chunk(int *pushed_value, int *start, int *end, int size);
int				inside_stack(t_stack *stack, int value, int size);
int				sort_a(t_pushswap *ps, int *up, int *down, int highest);
void			order(t_pushswap *ps, int *up, int *down);
int				canpush(t_pushswap *ps, int *up, int *down);
int				to_top(t_pushswap *ps, int highest);

//----------OPERATIONS----------//
void			sa(t_pushswap *ps);
void			sb(t_pushswap *ps);
void			ss(t_pushswap *ps);

void			pa(t_pushswap *ps);
void			pb(t_pushswap *ps);

void			ra(t_pushswap *ps);
void			rb(t_pushswap *ps);
void			rr(t_pushswap *ps);

void			rra(t_pushswap *ps);
void			rrb(t_pushswap *ps);
void			rrr(t_pushswap *ps);

//----------OPERATIONS UTILS----------//
void			insert_node(t_node *node, t_stack *stack);
t_node			*pop(t_stack *stack);
void			push(t_stack *stack1, t_stack *stack2);
void			swap(t_stack *stack);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);

//----------ARRAY UTILS----------//
int				*argv_to_array(char **argv, int size);
int				*bubblesort(int *stack, int size);

//----------CHUNK UTILS----------//
void			set_chunk(int *start, int *end, int size);
int				set_range(int size);

//----------UTILS----------//
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *nptr);
long			ft_atol(const char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);

#endif //PUSH_SWAP
