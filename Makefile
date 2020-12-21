CC	= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= ft_mini_ls
SRCS	= push_heap.c array_extend.c compare.c main.c pop_heap.c
OBJS	= $(SRCS:.c=.o)

all	: $(NAME)

.c.o	:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
	$(MAKE) -C libft all
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Llibft -lft

clean	:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean	:	clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re	:	fclean all

.PHONY	: clean fclean all re
