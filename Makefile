NAME	=	push_swap

SRCS	=	main.c             \
		verify_argvs.c     \
		stack_utils.c      \
		first_algorithm.c  \
		second_algorithm.c \
		quick.c            \
		s_operations.c     \
		p_operations.c     \
		r_operations.c     \
		rr_operations.c    \
		operations_utils.c \
		utils.c            \
		print_stacks.c

SRCS_BONUS	=	checker.c             \
			checker_utils.c       \
			get_next_line.c       \
			get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Werror -Wextra

RM	=	rm -rf 

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -c $<

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS_BONUS)
		$(CC) -o $(NAME) $(OBJS_BONUS)

.PHONY: all clean fclean re bonus
