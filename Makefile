NAME	=	push_swap

NAME_BONUS	=	checker	

SRCS	=	main.c             \
		verify_argvs.c     \
		array.c            \
		first_algorithm.c  \
		second_algorithm.c \
		third_algorithm.c  \
		a_to_b.c           \
		b_to_a.c           \
		chunk.c            \
		s.c                \
		p.c                \
		r.c                \
		rr.c               \
		stack_utils.c      \
		operations_utils.c \
		utils.c

SRCS_BONUS	=	checker_bonus.c             \
			verify_argvs_bonus.c        \
			array_bonus.c               \
			utils_bonus.c               \
			stack_utils_bonus.c         \
			s_bonus.c                   \
			p_bonus.c                   \
			r_bonus.c                   \
			rr_bonus.c                  \
			operations_utils_bonus.c    \
			checker_utils_bonus.c       \
			get_next_line_bonus.c       \
			get_next_line_utils_bonus.c

OBJS	=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Werror -Wextra -ggdb3

RM	=	rm -rf 

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

$(NAME_BONUS): $(OBJS_BONUS)
		$(CC) -o $(NAME_BONUS) $(OBJS_BONUS)

.c.o:
		$(CC) $(CFLAGS) -c $<

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus
