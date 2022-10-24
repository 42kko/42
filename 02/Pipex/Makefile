NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c parsing.c exec.c parsing_util1.c
OBJS = $(SRCS:.c=.o)

all: ft_Libft $(NAME)

ft_Libft:
	make -C ./Libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

clean:
	make -C ./Libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./Libft fclean
	rm -f $(NAME)

re: fclean all
