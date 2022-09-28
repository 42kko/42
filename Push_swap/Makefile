NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	err_utile.c parsing_utile1.c parsing_utile2.c push_swap.c \
	insert_utile.c command_utile1.c command_utile2.c \
	shortcase_utile.c utile.c utile2.c greedy.c
	

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
