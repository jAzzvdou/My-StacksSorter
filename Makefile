NAME	=	push_swap

SRCS	=	main.c             \
		operations.c       \
		operations_utils.c \
		print_stacks.c     \

OBJS	=	$(SRCS:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
