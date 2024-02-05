/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:11:33 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/05 15:27:30 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pushswap
{
	t_stack	*a;
	t_stack	*b;
}	t_pushswap;

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

//----------UTILS----------//
//size_t	ft_strlen(const char *str);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif //PUSH_SWAP
