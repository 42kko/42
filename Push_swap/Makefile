NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	err.c \
	insert.c \
	operations.c \
	parsing.c \
	print.c \
	push_swap.c \
	stack.c \
	sort.c

OBJS = $(SRCS:.c=.o)

all: ft_libft $(NAME)

ft_libft:
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

clean:
	make -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
