#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>

//----------STRUCT NODE----------//
typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
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

//----------UTILS----------//
size_t			my_strlen(const char *str);
int				my_atoi(const char *nptr);
long			my_atol(const char *nptr);
int				my_strncmp(const char *s1, const char *s2, size_t n);

//----------BONUS----------//
char			*my_strchr(const char *s, int c);
char			*my_strdup(const char *s);
char			*my_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
void			reader(t_pushswap *ps);

#endif //PUSH_SWAP_BONUS
