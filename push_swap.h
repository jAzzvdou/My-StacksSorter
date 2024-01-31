/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:11:33 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/31 20:23:48 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

// operations utils
int	swap(t_stack **stack);
int	push(t_stack **stack_from, t_stack **stack_to);
int	rotate(t_stack **stack);
int	reverse_rotate(t_stack **stack);

//----------OPERATIONS----------//
int	sa(t_pushswap *pushswap);
int	sb(t_pushswap *pushswap);
int	ss(t_pushswap *pushswap);

int	pa(t_pushswap *pushswap);
int	pb(t_pushswap *pushswap);

int	ra(t_pushswap *pushswap);
int	rb(t_pushswap *pushswap);
int	rr(t_pushswap *pushswap);

int	rra(t_pushswap *pushswap);
int	rrb(t_pushswap *pushswap);
int	rrr(t_pushswap *pushswap);

// debug
int	debugger(t_pushswap *pushswap);

#endif //PUSH_SWAP
